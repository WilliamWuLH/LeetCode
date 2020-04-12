## Merge Two Binary Trees

#### 深度优先搜索 DFS + 判断：

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        dfs(t1, t2, NULL, -1);
        return t1;
    }
    void dfs(TreeNode* t1, TreeNode* t2, TreeNode* root, int pos){
        if(t2 == NULL)
            return;
        if(t1 == NULL){
            if(pos)
                root->right = t2;
            else
                root->left = t2;
            return;
        }
        t1->val += t2->val;
        dfs(t1->left, t2->left, t1, 0);
        dfs(t1->right, t2->right, t1, 1);
    }
};
```

