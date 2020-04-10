## Path Sum III

#### 深度优先搜索 DFS：

​		每一个结点可以是一个新的起点，所以讨论分为两种：

1. 以此结点作为起始结点的新路径。
2. 包含该结点的路径。

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
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        dfs(root, 0, ans, sum, 0);
        return ans;
    }
    void dfs(TreeNode* root, int path, int &ans, int sum, int have){
        if(root == NULL)
            return;
        if(path + root->val == sum)
            ans++;
        if(have == 0){
            dfs(root->left, 0, ans, sum, 0);
            dfs(root->right, 0, ans, sum, 0);            
        }
        dfs(root->left, path+root->val, ans, sum, 1);
        dfs(root->right, path+root->val, ans, sum, 1);
    }
};
```

