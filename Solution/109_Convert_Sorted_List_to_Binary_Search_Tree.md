## Convert Sorted List to Binary Search Tree

Given the `head` of a singly linked list where elements are **sorted in ascending order**, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

**Example 1:**

```
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
```

**Example 2:**

```
Input: head = []
Output: []
```

**Example 3:**

```
Input: head = [0]
Output: [0]
```

**Example 4:**

```
Input: head = [1,3]
Output: [3,1]
```

**Constraints:**

- The number of nodes in `head` is in the range `[0, 2 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

#### 二分法 + 递归法：

​		一棵高度平衡的二叉搜索树，其左子树和右子树也是高度平衡的二叉搜索树。

​		**二分法**：将有序链表进行等分，链表的中间节点作为二叉搜索树的根节点，等分之后的前一部分链表用于构造左子树，等分之后的后一部分链表用于构造右子树。对于有序链表的二分法可以使用**快慢指针**得到中间节点（慢指针），这样就可以对链表进行等分。

​		**递归法**：因为高度平衡的二叉搜索树的特性，其左右子树都可以按照同样的模式进行构造，所以采用递归法。详细请看代码。

具体的分类讨论如下：

- 当链表中没有元素时，返回 NULL。
- 当链表中只有一个元素时，返回一个树节点（一棵树的根节点），节点值为该链表元素的值。
- 当链表中有多个元素时，使用快慢指针进行链表的二分法，并且分别递归构造其左子树和右子树，链表的中间元素为这个高度平衡的二叉搜索树的根节点，最后返回整一棵树。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        TreeNode* left_tree = sortedListToBST(head);
        TreeNode* right_tree = sortedListToBST(slow->next);
        TreeNode* root = new TreeNode(slow->val);
        root->left = left_tree;
        root->right = right_tree;
        return root;
    }
};
```

