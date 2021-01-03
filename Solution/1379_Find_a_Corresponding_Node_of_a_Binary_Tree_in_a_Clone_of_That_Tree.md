## Find a Corresponding Node of a Binary Tree in a Clone of That Tree

Given two binary trees `original` and `cloned` and given a reference to a node `target` in the original tree.

The `cloned` tree is a **copy of** the `original` tree.

Return *a reference to the same node* in the `cloned` tree.

**Note** that you are **not allowed** to change any of the two trees or the `target` node and the answer **must be** a reference to a node in the `cloned` tree.

**Follow up:** Solve the problem if repeated values on the tree are allowed.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e1.png)

```
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e2.png)

```
Input: tree = [7], target =  7
Output: 7
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e3.png)

```
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
```

**Example 4:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e4.png)

```
Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5
```

**Example 5:**

![img](https://assets.leetcode.com/uploads/2020/02/21/e5.png)

```
Input: tree = [1,2,null,3], target = 2
Output: 2
```

**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 10^4]`.
- The values of the nodes of the `tree` are unique.
- `target` node is a node from the `original` tree and is not `null`.

#### 方法一：深度优先搜索

​		让原始树 original 和克隆树 cloned 同步进行深度优先搜索：

- 当搜索到 original == NULL 时，说明已经到最深深度了（叶节点），并且没有找到 target，所以返回 NULL。
- 当搜索到 original == target 时，说明此时原始树 original 已经到达 target，由于原始树 original 和克隆树 cloned 是同步进行搜索，所以此时克隆树 cloned 也到达它的 target，故返回此时的 cloned。
- 当此时 original 为其他节点时，继续进行深度优先搜索，先访问左子树，再访问右子树，并且需要判断当前是否已经找到了 target，即返回值不为 NULL。

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL)
            return NULL;
        if(original == target)
            return cloned;
        TreeNode* ret = getTargetCopy(original->left, cloned->left, target);
        if(ret != NULL)
            return ret;
        ret = getTargetCopy(original->right, cloned->right, target);
        return ret;
    }
};
```

