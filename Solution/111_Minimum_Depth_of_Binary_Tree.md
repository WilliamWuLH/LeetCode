## Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:** A leaf is a node with no children.

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: 2
```

**Example 2:**

```
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^5]`.
- `-1000 <= Node.val <= 1000`

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

