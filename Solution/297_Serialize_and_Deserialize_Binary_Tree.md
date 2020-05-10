## Serialize and Deserialize Binary Tree

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

