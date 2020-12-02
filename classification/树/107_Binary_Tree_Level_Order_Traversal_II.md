## Binary Tree Level Order Traversal II

Given a binary tree, return the *bottom-up level order* traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its bottom-up level order traversal as:

```
[
  [15,7],
  [9,20],
  [3]
]
```

#### 宽度优先搜索 BFS：

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<int, TreeNode*>> q;
        if(root == NULL)
            return ans;
        q.push(make_pair(1, root));
        while(!q.empty()){
            pair<int, TreeNode*> cur = q.front();
            q.pop();
            if(ans.size() < cur.first){
                vector<int> level;
                ans.insert(ans.begin(), level);
            }
            ans[0].push_back(cur.second->val);
            if(cur.second->left != NULL)
                q.push(make_pair(cur.first+1, cur.second->left));
            if(cur.second->right != NULL)
                q.push(make_pair(cur.first+1, cur.second->right));
        }
        return ans;
    }
};
```

