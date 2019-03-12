package golang

/*
题目：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
思路：用一个双端队列，我们并不把每一个值都存入双端队列，而是 把可能成为最大值的数值的下标存入队列的中，对头每次保存的是当前的最大值。首先在size返回内初始化队列，如果当前数组的值大于等于队列的尾端的值，则把队列尾端的值剔除出去，加入当前的值得下标。
接下来就是每次数组的值先和队列尾端的值比较，如果大于等于尾端的值则把尾端的值剔除出去，接下来和队列的头比较，如果队列的头中存的下标值不在窗口内（i-头下标>=size）则把头下标剔除出去，加入当前值的下标。
*/

func maxSlidingWindow(nums []int, k int) []int {
	result := []int{}
	if len(nums) == 0 {
		return result
	}

	window := []int{}
	for i, x := range nums {
		if i >= k && window[0] <= i-k {
			window = window[1:]
		}
		for len(window) != 0 && nums[window[len(window)-1]] <= x {
			window = []int{}
		}
		window = append(window, i)
		if i >= k-1 {
			result = append(result, nums[window[0]])
		}
	}
	return result
}
