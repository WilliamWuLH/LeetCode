## Minimum Absolute Difference in BST

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

