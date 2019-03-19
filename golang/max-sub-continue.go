/*
最长连续子序列
*/

package golang

func maxSubContinue(s1, s2 string) string {
	len1 := len(s1)
	len2 := len(s2)

	dp := make([][]int, len1)
	maxLen := 0
	endPos := 0

	for i := 0; i < len1; i++ {
		dp[i] = make([]int, len2+1)
		for j := 0; j < len2; j++ {
			if i == 0 || j == 0 {
				if s1[i] == s2[j] {
					dp[i][j] = 1
				} else {
					dp[i][j] = 0
				}
			} else {
				if s1[i] == s2[j] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = 0
				}
			}

			if maxLen < dp[i][j] {
				maxLen = dp[i][j]
				endPos = i
			}
		}
	}

	return s1[endPos-maxLen+1 : endPos+1]
}
