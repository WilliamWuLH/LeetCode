## House Robber III

#### 树形 DP 自顶向下：

​		到达每一个结点，讨论是偷还是不偷的情况，并且记录下当前的最优选择。

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
    int rob(TreeNode* root) {
        pair<int,int> ans;
        ans = thief(root);
        return max(ans.first, ans.second);
    }
    pair<int,int> thief(TreeNode* root){
        pair<int,int> ans;
        if(root == NULL)
            return ans;
        pair<int,int> left = thief(root->left);
        pair<int,int> right = thief(root->right);
        ans.first = max(left.first, left.second) + max(right.first, right.second);
        ans.second = root->val + left.first + right.first;
        return ans;
    }
};
```

