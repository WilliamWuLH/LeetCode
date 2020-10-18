## N-ary Tree Postorder Traversal

#### N叉树的后序遍历：

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        posto(root, ans);
        return ans;
    }
    void posto(Node* root, vector<int> &ans){
        if(root == NULL)
            return;
        for(auto child : root->children)
            posto(child, ans);
        ans.push_back(root->val);
        return;
    }
};
```

