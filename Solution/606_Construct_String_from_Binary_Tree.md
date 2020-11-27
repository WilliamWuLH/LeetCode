## Construct String from Binary Tree

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

**Example 1:**

```
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

Output: "1(2(4))(3)"
Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)".
```



**Example 2:**

```
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
```

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

