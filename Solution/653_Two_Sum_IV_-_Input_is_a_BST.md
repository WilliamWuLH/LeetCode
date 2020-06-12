## Two Sum IV - Input is a BST

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
    bool findTarget(TreeNode* root, int k) {
        map<int, int> exist;
        bool ans = false;
        inorder(root, exist, k, ans);
        return ans;
    }
    void inorder(TreeNode* root, map<int, int> &exist, int k, bool &ans){
        if(root == NULL || ans)
            return;
        inorder(root->left, exist, k, ans);
        if(exist.count(k - root->val)){
            ans = true;
            return;
        }
        exist[root->val]++;
        inorder(root->right, exist, k, ans);
    }
};
```

