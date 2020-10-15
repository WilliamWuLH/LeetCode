## Sum Root to Leaf Numbers

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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
    void dfs(TreeNode* root, int &ans, int sum){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            ans += sum * 10 + root->val;
            return;
        }
        if(root->left != NULL){
            int cur = sum*10 + root->val;
            dfs(root->left, ans, cur);
        }
        if(root->right != NULL){
            int cur = sum*10 + root->val;
            dfs(root->right, ans, cur);
        }
        return;
    }
};
```

