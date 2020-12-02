## Binary Tree Maximum Path Sum

Given a **non-empty** binary tree, find the maximum path sum.

For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. The path must contain **at least one node** and does not need to go through the root.

**Example 1:**

```
Input: root = [1,2,3]
Output: 6
```

**Example 2:**

```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 3 * 10^4]`.
- `-1000 <= Node.val <= 1000`

#### 二叉树的后序遍历：

​		重点难点：

1. 遍历到每一个结点，讨论该结点的最大路径和并且更新答案，在计算结点的最大路径和时需要考虑路径上有出现负数的情况，负数的路径就不要计算到最大路径和中。
2. 返回包含该结点的最大路径和，最大路径和可以是该结点本身，或者是该结点和它的左子树最大路径和，也可以是该结点和它的右子树的最大路径和。

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        postorder(root, ans);
        return ans;
    }
    int postorder(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        int lsum = postorder(root->left, ans);
        int rsum = postorder(root->right, ans);
        int pathcost = root->val;
        pathcost = lsum > 0 ? pathcost + lsum : pathcost;
        pathcost = rsum > 0 ? pathcost + rsum : pathcost;
        ans = max(ans, pathcost);
        return max(root->val, max(root->val + lsum, root->val + rsum));
    }
};
```

