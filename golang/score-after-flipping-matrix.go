/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column,
and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves,
every row of this matrix is interpreted as a binary number,
and the score of the matrix is the sum of these numbers.

Return the highest possible score.



Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/

package golang

func matrixScore(A [][]int) int {
	m := len(A)
	n := len(A[0])
	res := (1 << uint(n-1)) * m

	for j := 1; j < n; j++ {
		cur := 0
		for i := 0; i < m; i++ {
			if A[i][j] == A[i][0] {
				cur++
			}
		}
		res += max(cur, m-cur) * (1 << uint(n-j-1))
	}

	return res
}
