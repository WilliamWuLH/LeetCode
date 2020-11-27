## Path Sum III

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

**Example:**

```
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
```

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

