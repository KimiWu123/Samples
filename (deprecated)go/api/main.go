package main

import "fmt"

func main() {

	fmt.Println("=== API Starts ===")
	server := newServer()
	server.run(8088)
}
