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

func TestAverageOfLevels(t *testing.T) {
	node1 := &TreeNode{Val: 3}
	node2 := &TreeNode{Val: 9}
	node3 := &TreeNode{Val: 20}
	node4 := &TreeNode{Val: 15}
	node5 := &TreeNode{Val: 7}
	node1.Left = node2
	node1.Right = node3
	node3.Left = node4
	node3.Right = node5

	res := averageOfLevels(node1)
	fmt.Println(res)
}
