## Range Sum of BST

Given the `root` node of a binary search tree, return *the sum of values of all nodes with a value in the range `[low, high]`*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg)

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg)

```
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2 * 10^4]`.
- `1 <= Node.val <= 10^5`
- `1 <= low <= high <= 10^5`
- All `Node.val` are **unique**.

#### 中序遍历：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        inorder(root, ans, low, high);
        return ans;
    }
    void inorder(TreeNode* root, int &ans, int &low, int &high){
        if(root == nullptr)
            return;
        if(root->val >= low)
            inorder(root->left, ans, low, high);
        if(root->val >= low && root->val <= high)
            ans += root->val;
        if(root->val <= high)
            inorder(root->right, ans, low, high);
        return;
    }
};
```

