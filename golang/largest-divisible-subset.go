/*
Given a set of distinct positive integers,
find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

package golang

import "sort"

func largestDivisibleSubset(nums []int) []int {
	n := len(nums)

	dp := make([]int, n)
	pre := make([]int, n)

	sort.Ints(nums)
	max := 0
	index := -1

	for i := 0; i < n; i++ {
		dp[i] = 1
		pre[i] = -1

		for j := i - 1; j >= 0; j-- {
			if nums[i]%nums[j] == 0 {
				if dp[j]+1 > dp[i] {
					dp[i] = dp[j] + 1
					pre[i] = j
				}
			}
		}

		if dp[i] > max {
			max = dp[i]
			index = i
		}
	}

	var res []int
	for index != -1 {
		res = append(res, nums[index])
		index = pre[index]
	}

	return res
}
