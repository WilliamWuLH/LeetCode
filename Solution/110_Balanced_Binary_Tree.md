## Balanced Binary Tree

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

