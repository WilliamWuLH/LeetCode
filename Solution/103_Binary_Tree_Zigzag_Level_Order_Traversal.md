## Binary Tree Zigzag Level Order Traversal

#### 二叉树的锯齿形层次遍历：

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 0, n = nodes.size();
        while(!nodes.empty()){
            vector<int> ele;
            while(n--){
                TreeNode* temp = nodes.front();
                nodes.pop();
                ele.push_back(temp->val);
                if(temp->left != NULL)
                    nodes.push(temp->left);
                if(temp->right != NULL)
                    nodes.push(temp->right);
            }
            n = nodes.size();
            if(level%2)
                reverse(ele.begin(), ele.end());
            ans.push_back(ele);
            level++;
        }
        return ans;
    }
};
```

