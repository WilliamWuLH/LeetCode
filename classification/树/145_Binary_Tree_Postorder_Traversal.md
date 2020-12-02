## Binary Tree Postorder Traversal

Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.

**Example 1:**

```
Input: root = [1,null,2,3]
Output: [3,2,1]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

```
Input: root = [1,2]
Output: [2,1]
```

**Example 5:**

```
Input: root = [1,null,2]
Output: [2,1]
```

**Constraints:**

- The number of the nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

**Follow up:**

Recursive solution is trivial, could you do it iteratively?

#### 二叉树的后序遍历：

​		送分题。

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    void postorder(TreeNode* root, vector<int>& ans){
        if(root == NULL)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
};
```

