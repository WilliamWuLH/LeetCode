## Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

**Note:** A leaf is a node with no children.

**Example:**

```
Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
```

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

