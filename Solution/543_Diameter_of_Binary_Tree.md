## Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the **longest** path between any two nodes in a tree. This path may or may not pass through the root.

**Example:**
Given a binary tree

```
          1
         / \
        2   3
       / \     
      4   5    
```

Return **3**, which is the length of the path [4,2,1,3] or [5,2,1,3].

**Note:** The length of path between two nodes is represented by the number of edges between them.

#### 二叉树的后序遍历：

​		通过后序遍历，先得到左子树的直径，再得到右子树的直径，然后更新此时的最大直径，返回加上根结点后的整棵二叉树的直径。

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }
    int postorder(TreeNode* root, int &ans){
        if(root == NULL)
            return 0;
        int llen = postorder(root->left, ans);
        int rlen = postorder(root->right, ans);
        ans = max(ans, llen+rlen);
        return max(llen, rlen)+1;
    }
};
```

