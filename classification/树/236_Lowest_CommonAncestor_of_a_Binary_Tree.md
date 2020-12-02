## Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [1,2], p = 1, q = 2
Output: 1
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 10^5]`.
- `-10^9 <= Node.val <= 10^9`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the tree.

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

