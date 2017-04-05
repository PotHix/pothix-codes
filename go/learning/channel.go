package main

import (
	"fmt"
	"time"
)

func worker(ch chan struct{}) {
	// Receive a message from the main program.

	value := 1

	for value < 10 {
		<-ch
		fmt.Println("roger", value)
		time.Sleep(1 * time.Second)

		value += 1
	}

	// Send a message to the main program.
	close(ch)
}

func main() {
	ch := make(chan struct{})
	go worker(ch)

	value := 1

	for value < 10 {
		// Send a message
		ch <- struct{}{}
		value += 1
	}

	// Receive a message
	<-ch
	println("roger")
}
