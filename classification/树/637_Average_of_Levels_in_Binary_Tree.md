## Average of Levels in Binary Tree

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

**Example 1:**

```
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
```

**Note:**

1. The range of node's value is in the range of 32-bit signed integer.

#### 广度优先搜索 or 层次遍历：

​		给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

​		通过广度优先搜索或者层次遍历，计算每一层的节点值的总和和个数，然后求出每层节点的平均值，添加到答案数组中。

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL)
            return ans;
        queue<tuple<TreeNode*, int>> q;
        q.push(tuple<TreeNode*, int>(root, 0));
        double sum = 0;
        int cur_level = 0, cur_num = 0;
        while(! q.empty()){
            auto [node, l] = q.front();
            q.pop();
            if(cur_level != l){
                ans.emplace_back(sum / cur_num);
                sum = 0;
                cur_num = 0;
                cur_level++;
            }
            sum += node->val;
            cur_num++;
            if(node->left != NULL)
                q.push(tuple<TreeNode*, int>(node->left, cur_level+1));
            if(node->right != NULL)
                q.push(tuple<TreeNode*, int>(node->right, cur_level+1));
        }
        if(cur_num != 0)
            ans.emplace_back(sum / cur_num);
        return ans;
    }
};
```

