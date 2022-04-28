package main 

import (
	"fmt"
	"os"
	"os/user"
)

func main() {
	hostName, err := os.Hostname()
	if err != nil {
	panic(err)
	}

	current, err := user.Current()
	if err != nil {
	panic(err)
	}
	
	fmt.Println("hostname:", hostName)
	fmt.Println("username:", current.Username)
	fmt.Println("name:", current.Name)
}

