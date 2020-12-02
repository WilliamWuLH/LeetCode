## Unique Binary Search Trees II

Given an integer `n`, generate all structurally unique **BST's** (binary search trees) that store values 1 ... *n*.

**Example:**

```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

**Constraints:**

- `0 <= n <= 8`

#### 递归法：

​		二叉搜索树的特性：在一棵二叉搜索树中，左子树的所有节点的值都比根节点的值小，右子树的所有节点的值都比根节点的值大；同时，当前二叉搜索树的左子树和右子树也是二叉搜索树。

​		根据二叉搜索树的性质，我们使用递归法非常合适，详细请看代码。

​		重点难点：二叉搜索树有很多种不同的组织形式，同样道理，其左子树和右子树也有很多种不同的组织形式。我们必须遍历所有的二叉搜索树的根节点的情况，同时也必须遍历所有的左子树和右子树的情况。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        vector<TreeNode*> ans = GenerateTree(1, n);
        return ans;
    }
    vector<TreeNode*> GenerateTree(int start, int end){
        if(start > end)
            return {nullptr};
        vector<TreeNode*> ans_trees;
        for(int i = start; i<=end; i++){
            vector<TreeNode*> left_tree = GenerateTree(start, i-1);
            vector<TreeNode*> right_tree = GenerateTree(i+1, end);
            for(auto l : left_tree){
                for(auto r : right_tree){
                    TreeNode* cur_root = new TreeNode(i);
                    cur_root->left = l;
                    cur_root->right = r;
                    ans_trees.push_back(cur_root);
                }
            }
        }
        return ans_trees;
    }
};
```

