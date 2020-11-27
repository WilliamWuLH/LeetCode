## Minimum Absolute Difference in BST

Given a binary search tree with non-negative values, find the minimum [absolute difference](https://en.wikipedia.org/wiki/Absolute_difference) between values of any two nodes.

**Example:**

```
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
```

**Note:**

- There are at least two nodes in this BST.
- This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#### 中序遍历：

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
    int getMinimumDifference(TreeNode* root) {
        int pre = -1, ans = INT_MAX;
        inorder(root, pre, ans);
        return ans;
    }
    void inorder(TreeNode* root, int &pre, int &ans){
        if(root == NULL)
            return;
        inorder(root->left, pre, ans);
        if(pre >= 0)
            ans = min(ans, root->val - pre);
        pre = root->val;
        if(ans == 0)
            return;
        inorder(root->right, pre, ans);
    }
};
```

