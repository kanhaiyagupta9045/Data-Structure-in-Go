/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorder(root *TreeNode, ans *[]int){
    if root==nil{
        return
    }
    *ans = append(*ans, root.Val)
    preorder(root.Left,ans)
    preorder(root.Right,ans)
}
func preorderTraversal(root *TreeNode) []int {
    ans := make([]int,0)
    preorder(root,&ans)
    return ans
}