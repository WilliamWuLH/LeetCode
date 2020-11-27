## Find Mode in Binary Search Tree

Given a binary search tree (BST) with duplicates, find all the [mode(s)](https://en.wikipedia.org/wiki/Mode_(statistics)) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than or equal to** the node's key.
- The right subtree of a node contains only nodes with keys **greater than or equal to** the node's key.
- Both the left and right subtrees must also be binary search trees.

For example:
Given BST `[1,null,2,2]`,

```
   1
    \
     2
    /
   2
```

return `[2]`.

**Note:** If a tree has more than one mode, you can return them in any order.

**Follow up:** Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

#### 中序遍历 + 统计个数 + 判断是否加入答案：

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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int pre = INT_MAX, max = 0, count = 1;
        inorder(root, ans, pre, max, count);
        return ans;
    }
    void inorder(TreeNode* root, vector<int> &ans, int &pre, int &max, int &count){
        if(root == NULL)
            return;
        inorder(root->left, ans, pre, max, count);
        if(root->val == pre)
            count++;
        else if(root->val != pre){
            pre = root->val;
            count = 1;
        }
        if(count == max){
            if(ans.size() == 0 || (ans.size() > 0 && ans[ans.size()-1] != pre))
                ans.push_back(pre);
        }  
        else if(count > max){
            ans.clear();
            ans.push_back(pre);
            max = count;
        }
        inorder(root->right, ans, pre, max, count);
    }
};
```

