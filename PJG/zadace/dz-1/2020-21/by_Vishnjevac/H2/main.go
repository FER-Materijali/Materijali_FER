package main

import (
	"fmt"
	"strings"
)

func main() {
	numbers := "Lorem ipsum dolor sit amet"
	num, occurrence := countWords(numbers)
	fmt.Println(num, occurrence) // 5 map[amet:1 dolor:1 ipsum:1 lorem:1 sit:1]

}
func countWords(sentence string) (int, map[string]int) {
	wordMap := make(map[string]int)

	sentence = strings.ReplaceAll(sentence, ",", " ")
	sentence = strings.ReplaceAll(sentence, ".", " ")
	words := strings.Fields(sentence)

	for _, word := range words {
		if value, ok := wordMap[strings.ToLower(word)]; ok {
			wordMap[strings.ToLower(word)] = value + 1
		} else {
			wordMap[strings.ToLower(word)] = 1
		}
	}
	numOfWords := len(wordMap)
	return numOfWords, wordMap
}
