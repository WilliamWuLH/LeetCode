## Lowest Common Ancestor of a Binary Search Tree

#### 二叉搜索树的性质：

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        if(p->val > q->val)
            ans = lowestCommonAncestor(root, q, p);
        else if(root->val >= p->val && root->val <= q->val)
            ans = root;
        else if(root->val > q->val)
            ans = lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val)
            ans = lowestCommonAncestor(root->right, p, q);
        return ans;
    }
};
```

