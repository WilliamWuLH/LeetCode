## Construct Binary Tree from Preorder and Inorder Traversal

#### 分治 + 递归：

​			前序遍历的第一个值为该二叉树的根结点值。

​			根据得到的根结点值，可以在中序遍历中找到该根结点值的位置，由于中序遍历是先左子树，再根结点，再右子树，所以在中序遍历中，根结点的位置划分出来的左边为左子树，右边为右子树。

​			根据中序遍历中根结点的位置左边的元素个数，可以得到左子树的结点个数，根据左子树的结点个数可以在前序遍历中得到左子树的前序遍历和右子树的前序遍历。

​			此时确定了根结点、左子树和右子树，把左子树和右子树当成是独立的一棵二叉树继续递归，并且返回子树的根结点，作为此时（大二叉树）根结点的左子结点和右子结点，由此构造出整棵二叉树。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return 0;
        TreeNode* root = new TreeNode(preorder[0]);
        int count = 0;
        for(count = 0; count < inorder.size(); count++){
            if(inorder[count] == preorder[0])
                break;
        }
        vector<int> pre1(preorder.begin()+1, preorder.begin()+1+count);
        vector<int> ino1(inorder.begin(), inorder.begin()+count);
        vector<int> pre2(preorder.begin()+1+count, preorder.end());
        vector<int> ino2(inorder.begin()+1+count, inorder.end());
        root->left = buildTree(pre1, ino1);
        root->right = buildTree(pre2, ino2);
        return root;
    }
};
```

