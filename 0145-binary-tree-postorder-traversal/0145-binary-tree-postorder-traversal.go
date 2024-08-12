/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func postorder(root *TreeNode, ans *[]int){
    if root==nil{
        return
    }
    postorder(root.Left,ans)
    postorder(root.Right,ans)
    *ans = append(*ans, root.Val)
}
func postorderTraversal(root *TreeNode) []int {
    ans := make([]int,0)
    postorder(root,&ans)
    return ans
}