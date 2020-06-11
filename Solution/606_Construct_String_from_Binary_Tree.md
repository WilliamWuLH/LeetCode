## Construct String from Binary Tree

#### 前序遍历：

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
    string tree2str(TreeNode* t) {
        string ans = "";
        preorder(t, ans, 0);
        return ans;
    }
    void preorder(TreeNode* t, string &ans, int dir){
        if(t == NULL)
            return;
        if(dir == 2 && ans.length() > 0 && ans[ans.length()-1] != ')')
            ans += "()";
        if(dir != 0)
            ans += "(";
        ans += to_string(t->val);
        preorder(t->left, ans, 1);
        preorder(t->right, ans, 2);
        if(dir != 0)
            ans += ")";
    }
};
```

