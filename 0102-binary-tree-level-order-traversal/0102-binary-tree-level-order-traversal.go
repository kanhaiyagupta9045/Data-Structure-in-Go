/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Node struct{
    node *TreeNode
}
func levelOrder(root *TreeNode) [][]int {
    ans := make([][]int,0)
    if root==nil{
        return ans
    }

    q := []Node{}
    q = append(q,Node{node:root})

    for len(q)>0{
        n := len(q)
        v := make([]int,0)
        for i:=0;i<n;i++{
            temp := q[0] // front node
            q = q[1:] // poping the node
            v = append(v,temp.node.Val)

            if temp.node.Left!=nil{
                q = append(q,Node{node:temp.node.Left})
            }
            if temp.node.Right!=nil{
                q = append(q,Node{node:temp.node.Right})
            }
        }
        ans = append(ans,v)
    }
    return ans


}