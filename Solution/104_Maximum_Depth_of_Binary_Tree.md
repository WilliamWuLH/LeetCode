## Maximum Depth of Binary Tree

#### 深度优先搜索 DFS：递归

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
    int ans = 0;
    int maxDepth(TreeNode* root) {
        dfs(1, root);
        return ans;
    }
    void dfs(int depth, TreeNode* root){
        if(root == NULL)
            return;
        ans = max(ans, depth);
        dfs(depth+1, root->left);
        dfs(depth+1, root->right);
    }
};
```

#### 深度优先搜索 DFS：栈 stack

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
    int maxDepth(TreeNode* root) {
        typedef pair<TreeNode*, int> depth;
        int ans = 0;
        stack<depth> nodes;
        depth d(root, 1);
        nodes.push(d);
        while(!nodes.empty()){
            depth temp = nodes.top();
            nodes.pop();
            if(temp.first != NULL){
                ans = max(ans, temp.second);
                depth l(temp.first->left, temp.second+1);
                nodes.push(l);
                depth r(temp.first->right, temp.second+1);
                nodes.push(r);
            }
        }
        return ans;
    }
};
```

