## Binary Tree Paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, ans, "");
        return ans;
    }
    void dfs(TreeNode* root, vector<string> &ans, string s){
        if(root == NULL)
            return;
        if(s == "")
            s += to_string(root->val);
        else
            s += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL)
            ans.push_back(s);
        dfs(root->left, ans, s);
        dfs(root->right, ans, s);
        return;
    }
};
```

