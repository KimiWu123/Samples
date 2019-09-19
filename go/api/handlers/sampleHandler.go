package handlers

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
)

type SampleHandler struct {
}

func NewSampleHandler() *SampleHandler {
	return &SampleHandler{}
}

func (*SampleHandler) Test(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("This is a test"))
}

func (*SampleHandler) SayHello(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("Hello~"))
}

func (*SampleHandler) PostMessage(w http.ResponseWriter, r *http.Request) {
	body, err := ioutil.ReadAll(io.LimitReader(r.Body, 1024*1024))
	if err != nil {
		msg := fmt.Sprintf("read http body failed, %s", err.Error())
		fmt.Println(msg)
		http.Error(w, msg, 520)
		return
	}
	err = r.Body.Close()
	if err != nil {
		fmt.Printf("close request body error: %s", err.Error())
	}
	fmt.Printf("Got %s", string(body))

	w.Write([]byte("Got your message: \n\t" + string(body)))
}

func (*SampleHandler) Upload(w http.ResponseWriter, r *http.Request) {

	uploadFolder := "./upload"

	// 10 << 20 --> 10MB
	r.ParseMultipartForm(10 << 20)
	file, handler, err := r.FormFile("filename")
	if err != nil {
		msg := fmt.Sprintf("Get file handler error, %s", err.Error())
		fmt.Println(msg)
		http.Error(w, msg, 520)
		return
	}
	defer file.Close()
	fmt.Printf("File: %v, size: %d\n", handler.Filename, handler.Size)

	if _, err := os.Stat(uploadFolder); os.IsNotExist(err) {
		os.Mkdir(uploadFolder, 0666)
	}
	f, err := os.OpenFile(uploadFolder+"/"+handler.Filename, os.O_WRONLY|os.O_CREATE, 0666)
	if err != nil {
		msg := fmt.Sprintf("Saving a file error, %s", err.Error())
		fmt.Println(msg)
		http.Error(w, msg, 520)
		return
	}
	defer f.Close()
	io.Copy(f, file)
}

// example: http://127.0.0.1:8088/v1/query?parm1=this_is_var1&parm2=this_is_var2
func (*SampleHandler) PostMessageWithQuery(w http.ResponseWriter, r *http.Request) {

	var1, var2 := "", ""
	parm1, ok := r.URL.Query()["parm1"]
	if !ok || len(parm1[0]) == 0 {
		fmt.Println("parm1 is null")
	} else {
		var1 = parm1[0]
	}
	parm2, ok := r.URL.Query()["parm2"]
	if !ok || len(parm2[0]) == 0 {
		fmt.Println("parm2 is null")
	} else {
		var2 = parm2[0]
	}

	fmt.Printf("Got parm1:%s, parm2:%s\n", var1, var2)
	w.Write([]byte("I don't care what you sent, here are your query values\n" + var1 + ", " + var2))
}
