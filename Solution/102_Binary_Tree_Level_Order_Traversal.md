## Binary Tree Level Order Traversal

#### 二叉树的层次遍历：

​			层次遍历需要记录遍历到哪一层。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(0, root, ans);
        return ans;
    }
    void levelorder(int level, TreeNode* root, vector<vector<int>>& ans){
        if(root == NULL)
            return;
        if(level >= ans.size()){
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        else
            ans[level].push_back(root->val);
        levelorder(level+1, root->left, ans);
        levelorder(level+1, root->right, ans);
    }
};
```

