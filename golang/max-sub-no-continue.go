/*
找到两个字符串非连续最大公共字符串。
*/

package golang

func maxSubString(s1, s2 string) int {
	len1 := len(s1)
	len2 := len(s2)

	dp := make([][]int, len1+1)

	for i := 0; i <= len1; i++ {
		dp[i] = make([]int, len2+1)
		for j := 0; j <= len2; j++ {
			if i == 0 || j == 0 {
				dp[i][j] = 0
			} else {
				if s1[i] == s2[j] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1])
				}
			}
		}
	}

	return dp[len1][len2]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
