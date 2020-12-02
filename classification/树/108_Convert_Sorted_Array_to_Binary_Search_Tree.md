## Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

**Example:**

```
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

#### 递归法 + 二分法：

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
            return NULL;
        int mid = nums.size()/2;
        vector<int> left_array(nums.begin(), nums.begin()+mid);
        vector<int> right_array(nums.begin()+mid+1, nums.end());
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(left_array);
        root->right = sortedArrayToBST(right_array);
        return root;
    }
};
```

