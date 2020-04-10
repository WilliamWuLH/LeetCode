## Diameter of Binary Tree

#### 二叉树的后序遍历：

​		通过后序遍历，先得到左子树的直径，再得到右子树的直径，然后更新此时的最大直径，返回加上根结点后的整棵二叉树的直径。

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
    int postorder(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        int llen = postorder(root->left, ans);
        int rlen = postorder(root->right, ans);
        ans = max(ans, llen+rlen);
        return max(llen, rlen)+1;
    }
};
```

