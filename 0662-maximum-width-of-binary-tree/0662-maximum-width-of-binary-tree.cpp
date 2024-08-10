/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#define i long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        i ans = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            int minIndex = q.front().second;
            i  first,last;
            for (int j = 0; j < n; j++) {
                auto it = q.front();
                int curr_index = it.second - minIndex;
                q.pop();
                if(j == 0){
                    first = curr_index;
                }
                if(j==n-1){
                    last = curr_index;
                }

                if(it.first->left){
                    q.push({it.first->left,2*curr_index+1});
                }
                if(it.first->right){
                    q.push({it.first->right,2*curr_index+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};