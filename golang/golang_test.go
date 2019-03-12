package golang

import (
	"fmt"
	"testing"
)

func TestStrstr(t *testing.T) {
	haystack := "hello"
	needle := "ll"
	res := strStr(haystack, needle)
	fmt.Println(res)
	if res != 2 {
		t.Error("bad")
	}

	needle = "hello"
	res = strStr(haystack, needle)
	fmt.Println(res)
	if res != 0 {
		t.Error("bad")
	}
}

func TestBubbleSort(t *testing.T) {
	s := []int{9, 5, 7, 10, 1, 3, 2, 4}
	quickSort(s)
	fmt.Println(s)
}
