## Symmetric Tree

#### 迭代法：

​			大问题变成小问题，不断迭代到可以进行判断，再返回判断结果。

​			判断两边：

- 首先判断两个根结点是否相同；

- 再判断左边根结点的左子树和右边根结点的右子树是否相同；

- 再判断左边根结点的右子树和右边根结点的左子树是否相同；

  ​	在判断是否相同时：

- 两个根结点均为 null，返回 true；
- 两个根结点中有一个是 null，有一个不是，返回 false；
- 两个根结点均不为 null，判断两个根结点的 val 值是否相同，再判断它们的左右子树。

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return mirror(root->left, root->right);
    }
    bool mirror(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        else if(node1 == NULL || node2 == NULL)
            return false;
        else
            return (node1->val == node2->val) 
                    && mirror(node1->left, node2->right)
                    && mirror(node1->right, node2->left);
    }
};
```

