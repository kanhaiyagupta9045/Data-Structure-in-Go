/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorder(root *TreeNode, ans *[]int){
    if root==nil{
        return
    }
    inorder(root.Left,ans)
    *ans = append(*ans, root.Val)
    inorder(root.Right,ans)
}
func inorderTraversal(root *TreeNode) []int {
    ans := make([]int,0)
    inorder(root,&ans)
    return ans
}