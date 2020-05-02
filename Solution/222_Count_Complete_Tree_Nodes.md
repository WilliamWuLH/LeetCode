## Count Complete Tree Nodes

#### 递归：

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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```

#### 二分查找：

​		根据完全二叉树的特性，在最后一层找最后一个在哪里，然后计算总的结点数目。

```c++

```

