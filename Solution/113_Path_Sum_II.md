## Path Sum II

#### 回溯法（其实就是深度优先搜索）：

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root != NULL){
            vector<int> path;
            path.push_back(root->val);
            backtrack(root, sum, root->val, ans, path);
        }
        return ans;
    }
    void backtrack(TreeNode* root, int sum, int count, vector<vector<int>> &ans,vector<int> &path){
        if(root->left == NULL && root->right == NULL){
            if(count == sum)
                ans.push_back(path);
            return;
        }
        if(root->left != NULL){
            path.push_back(root->left->val);
            backtrack(root->left, sum, count+root->left->val, ans, path);
            path.pop_back();
        }
        if(root->right != NULL){
            path.push_back(root->right->val);
            backtrack(root->right, sum, count+root->right->val, ans, path);
            path.pop_back();
        }
        return;
    }
};
```

