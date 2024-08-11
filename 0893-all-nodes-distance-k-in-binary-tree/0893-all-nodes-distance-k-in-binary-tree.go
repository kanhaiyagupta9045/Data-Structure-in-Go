/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "fmt"

type Node struct {
	node *TreeNode
}

func findparents(m *map[*TreeNode]*TreeNode, root *TreeNode) {
	q := []Node{}
	q = append(q, Node{node: root})

	for len(q) > 0 {
		temp := q[0]
		q = q[1:]

		if temp.node.Left!=nil {
			q = append(q, Node{node: temp.node.Left})
			(*m)[temp.node.Left] = temp.node
		}
		if temp.node.Right!=nil {
			q = append(q, Node{node: temp.node.Right})
			(*m)[temp.node.Right] = temp.node
		}
	}
}
func distanceK(root *TreeNode, target *TreeNode, k int) []int {

	// create a map
	m := make(map[*TreeNode]*TreeNode)
    findparents(&m,root)
    vis := make(map[*TreeNode]bool)
    vis[target]=true
    q := []Node{}
    q = append(q,Node{node:target})
    cnt :=0
    for len(q) > 0 {
        n := len(q)
        if cnt == k {
            break
        }

        for i := 0; i < n; i++ {
            temp := q[0]
            q = q[1:]
            if temp.node.Left != nil && !vis[temp.node.Left] {
                vis[temp.node.Left] = true
                q = append(q, Node{node: temp.node.Left})
            }
            if temp.node.Right != nil && !vis[temp.node.Right] {
                vis[temp.node.Right] = true
                q = append(q, Node{node: temp.node.Right})
            }
            if m[temp.node] != nil && !vis[m[temp.node]] {
                vis[m[temp.node]] = true
                q = append(q, Node{node: m[temp.node]})
            }
        }
        cnt++
    }
    ans := make([]int,0)
    for len(q)>0{
        temp := q[0]
        q = q[1:]
        ans = append(ans,temp.node.Val)
    }

    return ans

}