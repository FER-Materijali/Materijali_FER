package main

import (
	"encoding/json"
	"net/http"
	"strconv"
	"strings"
)

// http://localhost:8080/add/?n1=10&n2=100 vraća {"n1":10,"n2":100,"r":110}

type webResponseAdd struct {
	Number1 int `json:"n1"` // input number1
	Number2 int `json:"n2"` // input number2
	Result  int `json:"r"`  // result of number1 + number2
}

func main() {
	http.HandleFunc("/add/", add)
	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		return
	}
}
func add(w http.ResponseWriter, r *http.Request) {
	pathStripped := strings.TrimLeft(r.URL.String(), "/add/")

	elements := strings.Split(pathStripped, "&")
	if len(elements) != 2 {
		http.Error(w, "Number of arguments is not 2", 400)
		return
	}

	number1, err1 := strconv.Atoi(strings.Split(elements[0], "=")[1])
	number2, err2 := strconv.Atoi(strings.Split(elements[1], "=")[1])
	if err1 != nil || err2 != nil {
		http.Error(w, "One or more given args has invalid syntax", 400)
		return
	}

	webResponse := webResponseAdd{
		Number1: number1,
		Number2: number2,
		Result:  number1 + number2,
	}

	json.NewEncoder(w).Encode(webResponse)
}
