## House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

**Example 1:**

```
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

**Example 2:**

```
Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

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

