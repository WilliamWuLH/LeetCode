## Merge Two Binary Trees

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

**Example 1:**

```
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
```

**Note:** The merging process must start from the root nodes of both trees.

#### 深度优先搜索 DFS + 判断：

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        dfs(t1, t2, NULL, -1);
        return t1;
    }
    void dfs(TreeNode* t1, TreeNode* t2, TreeNode* root, int pos){
        if(t2 == NULL)
            return;
        if(t1 == NULL){
            if(pos)
                root->right = t2;
            else
                root->left = t2;
            return;
        }
        t1->val += t2->val;
        dfs(t1->left, t2->left, t1, 0);
        dfs(t1->right, t2->right, t1, 1);
    }
};
```

