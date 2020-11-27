## Binary Tree Level Order Traversal

Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
]
```

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

