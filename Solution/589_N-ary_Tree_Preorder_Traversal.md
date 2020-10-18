## N-ary Tree Preorder Traversal

#### N叉树的前序遍历：

​		递归法。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        po(root, ans);
        return ans;
    }
    void po(Node* root, vector<int> &ans){
        if(root == NULL)
            return;
        ans.push_back(root->val);
        for(auto child : root->children)
            po(child, ans);
        return;
    }
};
```

