package main

import (
	"fmt"
	"net/http"

	"./handlers"

	"github.com/gorilla/mux"
	"github.com/rs/cors"
)

const ver = "0.1.0"

// Route is basic struct to add to router
type Route struct {
	Name        string
	Method      string
	Pattern     string
	Queries     []string
	HandlerFunc http.HandlerFunc
}

// Server ...
type Server struct {
	router *mux.Router
	server *http.Server
}

var server *Server

// NewServer ...
func newServer() *Server {
	server = new(Server)
	server.router = mux.NewRouter().StrictSlash(true)
	return server
}

func version(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, ver)
}

func helloworld(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "hello")
}

// Run start a http server on X port
func (s *Server) run(port int) {
	fmt.Printf("api version: %s, port: %d\n", ver, port)
	s.addHandlers()
	s.server = &http.Server{Addr: fmt.Sprintf(":%d", port), Handler: s.router}
	err := s.server.ListenAndServe()
	if err != nil {
		fmt.Printf("init fail : %s", err.Error())
	}
}

func (s *Server) stop() {
	s.server.Close()
}

func (s *Server) addHandlers() {

	s.addRoutes([]Route{
		{Name: "hello", Method: "GET", Pattern: "/", HandlerFunc: http.HandlerFunc(helloworld)},
		{Name: "version", Method: "GET", Pattern: "/v", HandlerFunc: http.HandlerFunc(version)},
		{Name: "version", Method: "GET", Pattern: "/version", HandlerFunc: http.HandlerFunc(version)}})

	// Sample handler...
	handler := handlers.NewSampleHandler()
	if handler == nil {
		panic("new sample handler failed")
	}
	s.addRoutes([]Route{
		{Name: "test", Method: "GET", Pattern: "/v1/test", HandlerFunc: handler.Test},
		{Name: "say hello", Method: "GET", Pattern: "/v1/sayhello", HandlerFunc: handler.SayHello},
		{Name: "upload files", Method: "POST", Pattern: "/v1/upload", HandlerFunc: handler.Upload},
		{Name: "push", Method: "POST", Pattern: "/v1/post", HandlerFunc: handler.PostMessage},
		{Name: "query", Method: "GET", Pattern: "/v1/query", Queries: []string{"parm1", "parm2"}, HandlerFunc: handler.PostMessageWithQuery},
	})

	// special case for downloading
	s.router.PathPrefix("/v1/download/").Handler(
		http.StripPrefix("/v1/download/", http.FileServer(http.Dir("./upload"))))
}

func (s *Server) addRoutes(routes []Route) error {
	for _, route := range routes {
		handler := cors.AllowAll().Handler(route.HandlerFunc)
		s.router.
			Methods(route.Method).
			Path(route.Pattern).
			Name(route.Name).
			Handler(handler)
		if len(route.Queries) > 0 {
			for _, q := range route.Queries {
				if len(q) > 0 {
					s.router.Queries(q, "{"+q+"}")
				}
			}
		}
	}
	return nil
}
