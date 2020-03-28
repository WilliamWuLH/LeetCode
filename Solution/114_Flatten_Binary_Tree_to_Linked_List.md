## Flatten Binary Tree to Linked List

#### 先序遍历 + 插入子树：

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
    void flatten(TreeNode* root) {
        while(root != NULL){
            if(root->left == NULL)
                root = root->right;
            else{
                TreeNode* r = root->left;
                while(r->right != NULL)
                    r = r->right;
                r->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
        }
    }
};
```

