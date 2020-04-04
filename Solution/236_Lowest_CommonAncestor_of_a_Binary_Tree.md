## Lowest Common Ancestor of a Binary Tree

#### 递归 DFS + 公共前缀：

​		思路很简单：先对两个结点进行深度优先搜索，并且记录搜索的路径，走左子树的话路径记录为 0，走右子树的话记录为 1，由此记录方式可以唯一并且准确记录从根结点到达目标结点的路径。

​		然后再判断这两个目标结点的路径的公共前缀，即到达这两个目标结点必须经过的共同路径。

​		找到它们的共同路径，在共同路径（公共前缀）的最后一个结点就-是这两个目标结点的最近公共祖先。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> ppath, qpath;
        dfs(root, p, ppath);
        dfs(root, q, qpath);
        int len = min(ppath.size(), qpath.size());
        for(int i=0; i<len; i++){
            if(ppath[i] != qpath[i])
                break;
            if(ppath[i])
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
    bool dfs(TreeNode* root, TreeNode* target, vector<int> &path){
        if(root == target)
            return true;
        if(root != NULL){
            if(root->left != NULL){
                path.push_back(0);
                if( dfs(root->left, target, path) )
                    return true;
                path.pop_back();
            }
            if(root->right != NULL){
                path.push_back(1);
                if( dfs(root->right, target, path) )
                    return true;
                path.pop_back();
            }
        }
        return false;
    }
};
```

