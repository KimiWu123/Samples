package main

import (
	"bytes"
	"fmt"
	"io"
	"mime/multipart"
	"net/http"
	"os"
	"time"
)

func main() {
	url := "http://127.0.0.1:8088"
	err := UploadeFile(url+"/v1/upload", "test1.txt")
	if err != nil {
		return
	}
	time.Sleep(3 * time.Second)

	DownloadFile(url+"/v1/download/test1.txt", "dtest1.txt")
	if err != nil {
		return
	}

}

func UploadeFile(url string, filename string) error {
	bodyBuf := &bytes.Buffer{}
	bodyWriter := multipart.NewWriter(bodyBuf)

	// "filename" here is fixed,
	// if one wants to change, has to change the name in "Upload" in sampleHandler.go
	fileWriter, err := bodyWriter.CreateFormFile("filename", filename)
	if err != nil {
		fmt.Println("error writing to buffer")
		return err
	}

	// open file handle
	fh, err := os.Open(filename)
	if err != nil {
		fmt.Println("error opening file")
		return err
	}
	defer fh.Close()

	//iocopy
	_, err = io.Copy(fileWriter, fh)
	if err != nil {
		return err
	}

	contentType := bodyWriter.FormDataContentType()
	bodyWriter.Close()

	resp, err := http.Post(url, contentType, bodyBuf)
	if err != nil {
		return err
	}
	defer resp.Body.Close()
	// resp_body, err := ioutil.ReadAll(resp.Body)
	// if err != nil {
	// 	return err
	// }
	fmt.Println("upload status:" + resp.Status)
	// fmt.Println(string(resp_body))
	return nil
}

func DownloadFile(url string, filepath string) error {

	// Create the file
	out, err := os.Create(filepath)
	if err != nil {
		return err
	}
	defer out.Close()

	// Get the data
	resp, err := http.Get(url)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	// Write the body to file
	_, err = io.Copy(out, resp.Body)
	if err != nil {
		return err
	}
	fmt.Println("download status:" + resp.Status)

	return nil
}
