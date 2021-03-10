## Add One Row to Tree

Given the root of a binary tree, then value `v` and depth `d`, you need to add a row of nodes with value `v` at the given depth `d`. The root node is at depth 1.

The adding rule is: given a positive integer depth `d`, for each NOT null tree nodes `N` in depth `d-1`, create two tree nodes with value `v` as `N's` left subtree root and right subtree root. And `N's` **original left subtree** should be the left subtree of the new left subtree root, its **original right subtree** should be the right subtree of the new right subtree root. If depth `d` is 1 that means there is no depth d-1 at all, then create a tree node with value **v** as the new root of the whole original tree, and the original tree is the new root's left subtree.

**Example 1:**

```
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   
```

**Example 2:**

```
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
```

**Note:**

1. The given d is in range [1, maximum depth of the given tree + 1].
2. The given binary tree has at least one tree node.

#### 广度优先搜索 BFS + 分类讨论：

​		题目给定一个二叉树，根节点为第 1 层，深度为 1。在其第 d 层追加一行值为 v 的节点。

​		添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。

​		将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。

​		如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

解题思路：

​		本题使用广度优先搜索很好理解。首先分类讨论，如果 d == 1 或者 root == NULL，说明当前添加的节点是根节点，不需要遍历搜索，直接新建节点并且把树添加到根节点上，返回答案。

​		如果 d > 1，此时需要进行广度优先搜索，在 BFS 过程中需要记录每个节点的深度 depth，找出所有深度为 d-1 的节点，并且新建节点作为它的左右节点，即新增了一行，然后再把原先的左右子树添加回新的节点后面。

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1 || root == NULL){
            TreeNode* cur = new TreeNode(v);
            cur->left = root;
            return cur;
        }
        queue<tuple<TreeNode*, int>> q;
        q.push(tuple<TreeNode*, int>(root, 1));
        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();
            if(depth < d-1){
                if(node->left != NULL)
                    q.push(tuple<TreeNode*, int>(node->left, depth+1));
                if(node->right != NULL)
                    q.push(tuple<TreeNode*, int>(node->right, depth+1));
            }
            else if(depth == d-1){
                TreeNode* l = new TreeNode(v);
                TreeNode* r = new TreeNode(v);
                l->left = node->left;
                r->right = node->right;
                node->left = l;
                node->right = r;
            }
        }
        return root;
    }
};
```

