## Count Complete Tree Nodes

#### 递归：

​		时间复杂度：O(n)，空间复杂度：O(1)

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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```

### 2020.11.24 反思总结

​		首先我们想一想完全二叉树，有没有什么特殊的数据结构是完全二叉树呢？堆！堆排序！

​		然后再想一想，既然堆是完全二叉树，那么为什么堆排序那么稳定而且快呢？存储方式！

​		完全二叉树一般采用顺序存储结构，就是开一个数组存整棵树，所以很容易在 O(1) 的时间找到整棵树的任意一个节点，但是这道题偏偏采用链表存储结构，导致题目难度上升。

#### 根据完全二叉树的性质简化遍历次数

​		完全二叉树的性质：除了树的最后一层外，其余每一层的节点全部铺满，并且最后一层的节点按照从左往右的顺序。可以进行如下判断：

- 如果根节点的左子树深度等于右子树深度，则说明左子树为满二叉树。
- 如果根节点的左子树深度大于右子树深度，则说明右子树为满二叉树。
- 如果知道子树是满二叉树，那么就可以轻松得到该子树的节点数目：**(1 << depth) - 1**

时间复杂度：O(logn * logn)，空间复杂度：O(1)

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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_level = countlevel(root->left);
        int right_level = countlevel(root->right);
        if(left_level == right_level)
            return countNodes(root->right) + (1 << left_level) - 1 + 1;
        else
            return countNodes(root->left) + (1 << right_level) - 1 + 1;
    }
    int countlevel(TreeNode* root){
        int l = 0;
        while(root){
            root = root->left;
            l++;
        }
        return l;
    }
};
```

#### 二分查找：

​		对于最大层数为 h 的完全二叉树，节点个数一定在 [ 2^h, 2^(h+1) - 1 ] 的范围内，可以在该范围内通过二分查找的方式得到完全二叉树的节点个数。

​		根据节点个数范围的上下界得到当前需要判断的节点个数 k，如果第 k 个节点存在，则节点个数一定大于或等于 k，如果第 k 个节点不存在，则节点个数一定小于 k，由此可以将查找的范围缩小一半，直到得到节点个数。

​		**如何判断第 k 个节点是否存在呢？**

​		如果第 k 个节点位于第 h 层，则 k 的二进制表示包含 h+1 位，其中最高位是 1，其余各位从高到低表示从根节点到第 k 个节点的路径，0 表示移动到左子节点，1 表示移动到右子节点。

​		通过位运算得到第 k 个节点对应的路径，判断该路径对应的节点是否存在，即可判断第 k 个节点是否存在。


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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* temp = root;
        int h = 0;
        while(temp->left){
            temp = temp->left;
            h++;
        }
        int l = 1 << h, r = (1 << (h+1)) - 1;
        while(l < r){
            int mid = (r - l + 1)/2 + l;
            bool exist = !(not_exist(root, mid, h));
            if(exist)
                l = mid;
            else
                r = mid-1;
        }
        return l;
    }
    bool not_exist(TreeNode* root, int mid, int h){
        while(h && root){
            int flag = 1 << (h-1);
            int temp = mid & flag;
            if(temp == flag)
                root = root->right;
            else
                root = root->left;
            h--;
        }
        return root == NULL;
    }
};
```

