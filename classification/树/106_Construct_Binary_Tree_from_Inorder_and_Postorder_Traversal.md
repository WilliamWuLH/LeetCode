## Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

**Note:**
You may assume that duplicates do not exist in the tree.

For example, given

```
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
```

Return the following binary tree:

```
    3
   / \
  9  20
    /  \
   15   7
```

#### 递归法：

​		充分理解中序遍历 Inorder 和后序遍历 Postorder 的物理含义。

​		递归构造树：

- 后序遍历的最后一个值肯定是根节点的值，即后序遍历的最后一个元素就是树的根节点。
- 根据后序遍历得到的根节点，可以在中序遍历中确定树的左子树和右子树。
- 再根据中序遍历中确定的左子树和右子树可以在后序遍历中确定其子树的后序遍历，这样就得到了左子树和右子树的中序遍历和后序遍历。
- 这样，我们把一个大问题（整棵树）变成了几个小问题（根节点，左子树，右子树），就是所谓递归的思想。
- 不断递归到没有元素时返回 NULL，再一层层返回到最终的树，得到答案。

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        int root_val = postorder[ postorder.size() - 1 ];
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), root_val);
        TreeNode* left_tree = NULL;
        TreeNode* right_tree = NULL;
        int right_num = inorder.end() - it -  1;
        if(it != inorder.end()-1){
            vector<int> left_in_list(inorder.begin(), it);
            vector<int> left_post_list(postorder.begin(), postorder.end() - 1 - right_num);
            vector<int> right_in_list(it+1, inorder.end());
            vector<int> right_post_list(postorder.end() - 1 - right_num, postorder.end()-1);
            if(left_in_list.size())
                left_tree = buildTree(left_in_list, left_post_list);
            if(right_in_list.size())
                right_tree = buildTree(right_in_list, right_post_list);
        }
        else{
            vector<int> left_in_list(inorder.begin(), it);
            vector<int> left_post_list(postorder.begin(), postorder.end()-1);
            if(left_in_list.size())
                left_tree = buildTree(left_in_list, left_post_list);
        }
        TreeNode* root = new TreeNode(root_val);
        root->left = left_tree;
        root->right = right_tree;
        return root;
    }
};
```

