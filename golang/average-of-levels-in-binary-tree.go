/*
Given a non-empty binary tree,
return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,
on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
*/

package golang

// * Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func averageOfLevels(root *TreeNode) []float64 {
	var avg []float64

	q := newQueue()
	q.Offer(root)
	totalLen := 1
	curLen := 0
	var curSum float64
	for q.Len() > 0 {
		node := q.Poll().(*TreeNode)
		if node.Left != nil {
			q.Offer(node.Left)
		}
		if node.Right != nil {
			q.Offer(node.Right)
		}

		curSum += float64(node.Val)
		curLen++
		if curLen == totalLen {
			avg = append(avg, float64(curSum)/float64(curLen))
			curSum = 0
			totalLen = q.Len()
			curLen = 0
		}
	}

	return avg
}
