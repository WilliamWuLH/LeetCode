## Deepest Leaves Sum

Given the `root` of a binary tree, return *the sum of values of its deepest leaves*. 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)

```
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

**Example 2:**

```
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `1 <= Node.val <= 100`

#### 深度优先搜索：

​		进行简单的深度优先搜索 DFS。在 DFS 过程中维护两个变量：当前层数最深的叶子节点的和 ans 和当前最深的深度 deepest。

​		不断地进行 DFS，当当前深度 depth 大于最深的深度 deepest 时，更新最深深度 deepest 和当前层数最深的叶子节点的和 ans。当当前深度 depth 等于最深的深度 deepest 时，把当前结点的值 root->val 加到当前层数最深的叶子节点的和 ans。

​		最后返回层数最深的叶子节点的和 ans。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0, deepest = -1;
        dfs(root, 0, ans, deepest);
        return ans;
    }
    void dfs(TreeNode* root, int depth, int &ans, int &deepest){
        if(root == nullptr)
            return;
        if(depth > deepest){
            deepest = depth;
            ans = root->val;
        }
        else if(depth == deepest)
            ans += root->val;
        dfs(root->left, depth+1, ans, deepest);
        dfs(root->right, depth+1, ans, deepest);
        return;
    }
};
```

