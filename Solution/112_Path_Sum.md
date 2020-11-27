## Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and `sum = 22`,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

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

