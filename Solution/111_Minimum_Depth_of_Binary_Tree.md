## Minimum Depth of Binary Tree

#### 深度优先搜索 DFS：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;
        if(root == NULL)
            return 0;
        dfs(root, 1, ans);
        return ans;
    }
    void dfs(TreeNode* root, int depth, int & ans){
        if(root->left == NULL && root->right == NULL){
            ans = min(ans, depth);
            return;
        }
        if(root->left != NULL)
            dfs(root->left, depth+1, ans);
        if(root->right != NULL)
            dfs(root->right, depth+1, ans);
        return;
    }
};
```

