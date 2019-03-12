package golang

import (
	"sort"
)

func minIncrementForUnique(A []int) int {
	count := [100000]int{}
	max := 0

	for _, item := range A {
		if max < item {
			max = item
		}
		count[item] += 1
	}

	ans := 0
	taken := 0

	for x := 0; x < 100000; x += 1 {
		if count[x] >= 2 {
			taken += count[x] - 1
			ans -= x * (count[x] - 1)
		} else if taken > 0 && count[x] == 0 {
			taken -= 1
			ans += x
		}
	}

	return ans
}

func minIncrementForUnique2(A []int) int {
	sort.Ints(A)

	ans := 0
	taken := 0

	for i := 1; i < len(A); i += 1 {
		if A[i] == A[i-1] {
			taken += 1
			ans -= A[i]
		} else {
			given := Min(taken, A[i]-A[i-1]-1)
			ans += given*(given+1)/2 + given*A[i-1]
			taken -= given
		}
	}

	if len(A) > 0 {
		ans += taken*(taken+1)/2 + taken*A[len(A)-1]
	}

	return ans
}

func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
