## Path Sum

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
    bool hasPathSum(TreeNode* root, int sum) {
        bool ans = false;
        if(root != NULL)
            dfs(root, ans, root->val, sum);
        return ans;
    }
    void dfs(TreeNode* root, bool &ans, int count, int sum){
        if(ans == true)
            return;
        if(root->left == NULL && root->right == NULL){
            if(count == sum)
                ans = true;
            return;
        }
        if(root->left != NULL)
            dfs(root->left, ans, count+root->left->val, sum);
        if(root->right != NULL)
            dfs(root->right, ans, count+root->right->val, sum);
        return;
    }
};
```

