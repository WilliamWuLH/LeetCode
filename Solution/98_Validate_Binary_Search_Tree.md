## Validate Binary Search Tree

#### 关于二叉查找树的中序遍历：

​		根据二叉查找树的性质，对二叉查找树进行中序遍历可以得到一个有序的序列。

​		通过判断进行中序遍历得到的序列是否严格有序，可以得知这个二叉查找树是否正确（有效）。

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
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        int len = nums.size();
        for(int i=1; i<len; i++){
            if(nums[i] <= nums[i-1])
                return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};
```

