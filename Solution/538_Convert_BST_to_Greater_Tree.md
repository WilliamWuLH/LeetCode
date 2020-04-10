## Convert BST to Greater Tree

#### 二叉查找树的中序遍历逆过程：

​		遍历二叉查找树时：

1. 先遍历其右子树；
2. 再遍历其根结点；
3. 最后遍历其左子树。

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
    TreeNode* convertBST(TreeNode* root) {
        thesum(root, 0);
        return root;
    }
    int thesum(TreeNode* root, int sum){
        if(root == NULL)
            return sum;
        sum = thesum(root->right, sum);
        sum += root->val;
        root->val = sum;
        sum = thesum(root->left, sum);
        return sum;
    }
};
```

