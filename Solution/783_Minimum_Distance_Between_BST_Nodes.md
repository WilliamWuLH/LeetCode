## Minimum Distance Between BST Nodes

Given the `root` of a Binary Search Tree (BST), return *the minimum difference between the values of any two different nodes in the tree*.

**Note:** This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```
Input: root = [4,2,6,1,3]
Output: 1
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

```
Input: root = [1,0,48,null,null,12,49]
Output: 1
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 100]`.
- `0 <= Node.val <= 10^5`

#### 中序遍历：

抓住  **二叉搜索树**  这个性质，进行中序遍历，按照大小进行判断。

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
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, leftmax = INT_MAX;
        dfs(root, ans, leftmax);
        return ans;
    }
    void dfs(TreeNode* root, int &ans, int &leftmax){
        if(root == NULL)
            return;
        dfs(root->left, ans, leftmax);
        if(leftmax <= root->val)
            ans = min(ans, root->val - leftmax);
        leftmax = root->val;
        dfs(root->right, ans, leftmax);
        return;
    }
};
```

