## Rotate List

Given the `head` of a linked list, rotate the list to the right by `k` places.

**Example 1:**

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Example 2:**

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`

#### 链表成环 + 双指针：

​		首先，将链表的尾部和头部连接在一起，并且统计链表的结点个数。

​		然后，通过结点个数和移动的位置数目计算出应该在什么地方断开链表。

​		使用双指针是为了在到达正确位置的同时可以取到上一个结点的指针。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* index = head;
        ListNode* pre = index;
        int num = 0;
        while(index != NULL){
            pre = index;
            index = index->next;
            num++;
        }
        pre->next = head;
        k %= num;
        index = head;
        while(num-k){
            pre = index;
            index = index->next;
            num--;
        }
        pre->next = NULL;
        return index;
    }
};
```

