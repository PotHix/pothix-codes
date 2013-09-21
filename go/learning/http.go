// +build http

package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	resp, err := http.Get("http://pothix.com/blog/about")
	body, err := ioutil.ReadAll(resp.Body)
	fmt.Println(err)
	fmt.Println(string(body))
}
