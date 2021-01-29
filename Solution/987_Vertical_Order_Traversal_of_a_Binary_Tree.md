## Vertical Order Traversal of a Binary Tree

Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.

For each node at position `(x, y)`, its left and right children will be at positions `(x - 1, y - 1)` and `(x + 1, y - 1)` respectively.

The **vertical order traversal** of a binary tree is a list of non-empty **reports** for each unique x-coordinate from left to right. Each **report** is a list of all nodes at a given x-coordinate. The **report** should be primarily sorted by y-coordinate from highest y-coordinate to lowest. If any two nodes have the same y-coordinate in the **report**, the node with the smaller value should appear earlier.

Return *the **vertical order traversal** of the binary tree*.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/01/31/1236_example_1.PNG)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: Without loss of generality, we can assume the root node is at position (0, 0):
The node with value 9 occurs at position (-1, -1).
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2).
The node with value 20 occurs at position (1, -1).
The node with value 7 occurs at position (2, -2).
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/01/31/tree2.png)

```
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report [1,5,6], the node with value 5 comes first since 5 is smaller than 6.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`

#### 深度优先搜索 + 排序：

二叉树的垂序遍历：给定一棵二叉树，从左到右，从上到下，节点值从小到大，依次遍历二叉树中的每一个节点。

思路：

​		对位于 ( x ,  y ) 的每个结点而言，其左右子结点分别位于 ( x - 1 ,  y - 1 ) 和 ( x + 1 ,  y - 1 ) 。

​		我们设定根节点的坐标为 ( 0 ,  0 )。

​		先进行深度优先搜索，由于二叉树中每个节点的值是不同的，所以即使两个节点的坐标相同，它们的节点值不同也可以代表不同的元素，所以我们可以通过深度优先搜索确定每一个节点的坐标，再使用一个数据容器存储节点的坐标以及节点的值。

​		接下来就是进行排序，由于我们是要对二叉树进行垂序遍历，所以按照坐标的 x 值，y 值和节点值的大小进行排序，得到二叉树从左到右，从上到下，节点值从小到大的顺序。

​		最后，把排序的结果组织成答案并返回。

相关阅读：

- [tuple](http://www.cplusplus.com/reference/tuple/)：主要是 tuple 的基本用法

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        vector<tuple<int, int, int>> node_pos;
        backtrack(node_pos, root, 0, 0);
        sort(node_pos.begin(), node_pos.end(), [&](const auto& a, const auto& b){
            auto && [xa, ya, vala] = a;
            auto && [xb, yb, valb] = b;
            if(xa != xb)
                return xa < xb;
            if(ya != yb)
                return ya > yb;
            return vala < valb;
        });
        int curx = get<1>(node_pos[0]) - 1;
        int index = -1;
        for(auto &i : node_pos){
            auto && [x, y, val] = i;
            if(curx == x)
                ans[index].emplace_back(val);
            else{
                vector<int> temp = {val};
                ans.emplace_back(temp);
                curx = x;
                index++;
            }
        }
        return ans;
    }
    void backtrack(vector<tuple<int, int, int>> &node_pos, TreeNode* root, int x, int y){
        if(root == nullptr)
            return;
        tuple<int, int, int> pos(x, y, root->val);
        node_pos.emplace_back(pos);
        backtrack(node_pos, root->left, x-1, y-1);
        backtrack(node_pos, root->right, x+1, y-1);
        return;
    }
};
```

