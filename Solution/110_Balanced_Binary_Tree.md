## Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the left and right subtrees of *every* node differ in height by no more than 1.

**Example 1:**

```
Input: root = [3,9,20,null,null,15,7]
Output: true
```

**Example 2:**

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

**Example 3:**

```
Input: root = []
Output: true
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^4 <= Node.val <= 10^4`

#### 回溯法（计算树的高度）：

​		在计算树的高度的同时判断树是否为平衡二叉树，如果不是直接停止计算，返回结果。

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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int len = count(root, ans);
        return ans;
    }
    int count(TreeNode* root, bool &ans){
        if(ans == false)
            return 0;
        if(root == NULL){
            ans = true;
            return 0;
        }
        int left = count(root->left, ans);
        int right = count(root->right, ans);
        if(abs(left - right) > 1)
            ans = false;
        return max(left, right) + 1;
    }
};
```

