## Find Mode in Binary Search Tree

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

