package handlers

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
)

type SampleHander struct {
}

func NewSampleHandler() *SampleHander {
	return &SampleHander{}
}

func (*SampleHander) Test(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json; charset=UTF-8")

	w.Write([]byte("This is a test"))
}

func (*SampleHander) SayHello(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json; charset=UTF-8")

	w.Write([]byte("Hello~"))
}

func (*SampleHander) PostMessage(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json; charset=UTF-8")

	body, err := ioutil.ReadAll(io.LimitReader(r.Body, 1024*1024))
	if err != nil {
		msg := fmt.Sprintf("read http body failed, %s", err.Error())
		fmt.Println(msg)
		http.Error(w, msg, 502)
		return
	}
	err = r.Body.Close()
	if err != nil {
		fmt.Printf("close request body error: %s", err.Error())
	}
	fmt.Printf("Got %s", string(body))

	w.Write([]byte("Got your message: \n\t" + string(body)))
}
