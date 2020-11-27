## Populating Next Right Pointers in Each Node

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**Follow up:**

- You may only use constant extra space.
- Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

**Example 1:**

```
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Constraints:**

- The number of nodes in the given tree is less than `4096`.
- `-1000 <= node.val <= 1000`

#### 层次遍历：

​		对二叉树进行层次遍历，并且记录每个结点所在的高度，根据高度和是否存在下一个结点进行讨论。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        typedef pair<Node*, int> the_node;
        queue<the_node> q;
        q.push(the_node(root, 0));
        while(!q.empty()){
            the_node cur = q.front();
            q.pop();
            if(cur.first->left != NULL)
                q.push(the_node(cur.first->left, cur.second+1));
            if(cur.first->right != NULL)
                q.push(the_node(cur.first->right, cur.second+1));
            if(q.empty()){
                cur.first->next = NULL;
                break;
            }
            the_node next_node = q.front();
            if(cur.second != next_node.second)
                cur.first->next = NULL;
            else
                cur.first->next = next_node.first;
        }
        return root;
    }
};
```

