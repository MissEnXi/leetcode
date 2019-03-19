package golang

import (
	"container/list"
)

type stack struct {
	list list.List
}

func newStack() *list.List {
	return list.New()
}

func (s *stack) push(item int) {
	s.list.PushBack(item)
}

func (s *stack) pop() {
	e := s.list.Front()
	s.list.Remove(e)
}

func (s *stack) top() int {
	e := s.list.Back()
	return e.Value.(int)
}
