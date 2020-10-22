## Convert Sorted Array to Binary Search Tree

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

