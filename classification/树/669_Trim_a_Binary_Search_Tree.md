## Trim a Binary Search Tree

Given the `root` of a binary search tree and the lowest and highest boundaries as `low` and `high`, trim the tree so that all its elements lies in `[low, high]`. Trimming the tree should **not** change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a **unique answer**.

Return *the root of the trimmed binary search tree*. Note that the root may change depending on the given bounds.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/09/trim1.jpg)

```
Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/09/09/trim2.jpg)

```
Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
```

**Example 3:**

```
Input: root = [1], low = 1, high = 2
Output: [1]
```

**Example 4:**

```
Input: root = [1,null,2], low = 1, high = 3
Output: [1,null,2]
```

**Example 5:**

```
Input: root = [1,null,2], low = 2, high = 4
Output: [2]
```

**Constraints:**

- The number of nodes in the tree in the range `[1, 10^4]`.
- `0 <= Node.val <= 10^4`
- The value of each node in the tree is **unique**.
- `root` is guaranteed to be a valid binary search tree.
- `0 <= low <= high <= 10^4`

#### 递归：

​		本题就是对递归的深入理解！

我们可以把情况分为 4 种：

1. root == nullptr，该树是一棵空树，直接返回 nullptr。
2. root->val > high，表示该树的根节点的值比最大边界的值还大，说明该树的根节点和右子树不可取，答案只可能在该树的左子树，我们递归求解该树的左子树：return trimBST(root->left, low, high);
3. root->val < low，表示该树的根节点的值比最小边界的值还小，说明该树的根节点和左子树不可取，答案只可能在该树的右子树，我们递归求解该树的右子树：return trimBST(root->right, low, high);
4. low <= root->val <= high，表示该树的根节点属于规定范围内，递归求解该树的左子树和右子树，此时该树的左子树和右子树也应该符合规范的要求，所以可以递归求解。

具体代码如下：

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
            return root;
        if(root->val > high)
            return trimBST(root->left, low, high);
        if(root->val < low)
            return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```

