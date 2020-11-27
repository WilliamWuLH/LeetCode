## Two Sum IV - Input is a BST

Given the `root` of a Binary Search Tree and a target number `k`, return *`true` if there exist two elements in the BST such that their sum is equal to the given target*.

**Example 1:**

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

**Example 3:**

```
Input: root = [2,1,3], k = 4
Output: true
```

**Example 4:**

```
Input: root = [2,1,3], k = 1
Output: false
```

**Example 5:**

```
Input: root = [2,1,3], k = 3
Output: true
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-10^4 <= Node.val <= 10^4`
- `root` is guaranteed to be a **valid** binary search tree.
- `-10^5 <= k <= 10^5`

#### 中序遍历：

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
    bool findTarget(TreeNode* root, int k) {
        map<int, int> exist;
        bool ans = false;
        inorder(root, exist, k, ans);
        return ans;
    }
    void inorder(TreeNode* root, map<int, int> &exist, int k, bool &ans){
        if(root == NULL || ans)
            return;
        inorder(root->left, exist, k, ans);
        if(exist.count(k - root->val)){
            ans = true;
            return;
        }
        exist[root->val]++;
        inorder(root->right, exist, k, ans);
    }
};
```

