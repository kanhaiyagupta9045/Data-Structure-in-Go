/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func widthOfBinaryTree(root *TreeNode) int {
	type BT struct {
		Node  *TreeNode
		Index int64
	}
	ans := int64(0)
	q := []BT{{root, 0}}

	for len(q) > 0 {
		minIndex := q[0].Index
		n := len(q)
		var first, last int64
		for i := 0; i < n; i++ {
			currNode := q[0]
			q = q[1:]
			currIndex := currNode.Index - minIndex

			if i == 0 {
				first = currIndex
			}
			if i == n-1 {
				last = currIndex
			}

			if currNode.Node.Left != nil {
				q = append(q, BT{currNode.Node.Left, 2*currIndex + 1})
			}
			if currNode.Node.Right != nil {
				q = append(q, BT{currNode.Node.Right, 2*currIndex + 2})
			}
		}
		ans = max(ans, last-first+1)
	}
	return int(ans)
}
func max(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}