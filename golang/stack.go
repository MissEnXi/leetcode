package golang

import (
	"container/list"
)

type stack struct {
	list *list.List
}

func newStack() *stack {
	l := list.New()
	return &stack{list: l}
}

func (s *stack) push(item int) {
	s.list.PushBack(item)
}

func (s *stack) pop() (item int) {
	e := s.list.Back()
	s.list.Remove(e)
	return e.Value.(int)
}

func (s *stack) top() int {
	e := s.list.Back()
	return e.Value.(int)
}

type Queue struct {
	list *list.List
}

func newQueue() *Queue {
	l := list.New()
	return &Queue{list: l}
}

func (q *Queue) Offer(item interface{}) {
	q.list.PushBack(item)
}

func (q *Queue) Poll() interface{} {
	e := q.list.Front()
	q.list.Remove(e)
	return e.Value
}

func (q *Queue) Peek() interface{} {
	e := q.list.Front()
	return e.Value
}

func (q *Queue) Len() int {
	return q.list.Len()
}
