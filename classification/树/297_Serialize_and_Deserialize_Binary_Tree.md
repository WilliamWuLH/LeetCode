## Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://leetcode.com/faq/#binary-tree). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Example 1:**

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:**

```
Input: root = [1,2]
Output: [1,2]
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

#### 宽度优先搜索 BFS：

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
                ans += "null,";
            else{
                string theval = to_string(temp->val);
                ans += theval + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* ans = new TreeNode;
        queue< pair<TreeNode*,int> > q;
        vector<string> node;
        string temp = "";
        for(int i=0; i<data.length(); i++){
            if(data[i] == ','){
                node.push_back(temp);
                temp = "";
            }
            else
                temp += data[i];
        }
        q.push(make_pair(ans, 0));
        int pos = 0;
        while(!q.empty()){
            pair<TreeNode*,int> cur = q.front();
            q.pop();
            if(node[pos] == "null"){
                if(cur.second == 0)
                    cur.first->left = NULL;
                else
                    cur.first->right = NULL;
            }
            else{
                TreeNode* next = new TreeNode;
                next->val = atoi(node[pos].c_str());
                if(cur.second == 0)
                    cur.first->left = next;
                else
                    cur.first->right = next;
                q.push(make_pair(next,0));
                q.push(make_pair(next,1));
            }
            pos++;
        }
        return ans->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```

