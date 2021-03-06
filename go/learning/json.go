// +build json

package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	// var f interface{}
	resp, err := http.Get("https://urlhere.com.br")
	body, err := ioutil.ReadAll(resp.Body)

	container := make(map[string]interface{})
	err = json.Unmarshal(body, &container)
	if err != nil {
		panic(err)
	}

	fmt.Println(container["results"])
}
