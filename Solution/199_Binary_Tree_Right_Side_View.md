## Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the *right* side of it, return the values of the nodes you can see ordered from top to bottom.

**Example:**

```
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<int, TreeNode*>> q;
        if(root == NULL)
            return ans;
        pair<int, TreeNode*> rightest;
        q.push(make_pair(0, root));
        while(!q.empty()){
            pair<int, TreeNode*> cur = q.front();
            if(cur.first > rightest.first)
                ans.push_back(rightest.second->val);
            rightest = cur;
            q.pop();
            if(cur.second->left != NULL)
                q.push(make_pair(cur.first+1, cur.second->left));
            if(cur.second->right != NULL)
                q.push(make_pair(cur.first+1, cur.second->right));
        }
        ans.push_back(rightest.second->val);
        return ans;
    }
};
```

