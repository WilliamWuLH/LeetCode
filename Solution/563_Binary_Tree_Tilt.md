## Binary Tree Tilt

#### 后序遍历：

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
    int findTilt(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
    int postorder(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        int left = postorder(root->left, ans);
        int right = postorder(root->right, ans);
        ans += abs(left-right);
        return left+right+root->val;
    }
};
```

