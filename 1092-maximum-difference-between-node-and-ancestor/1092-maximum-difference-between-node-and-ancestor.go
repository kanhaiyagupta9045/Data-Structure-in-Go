/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func Helper(root *TreeNode, small,large int , ans *int){
    if root==nil{
        return
    }

    if root.Val >large{
        large = root.Val
    }

    if root.Val<small{
        small = root.Val
    }

    Helper(root.Left,small,large,ans)
    Helper(root.Right,small, large,ans)

    *ans = max(*ans,large-small)
    return
}

func max(a,b int)int{
    if a>=b{
        return a
    }
    return b
}
func maxAncestorDiff(root *TreeNode) int {
    ans :=0;
    Helper(root,root.Val,root.Val,&ans)
    return ans
}