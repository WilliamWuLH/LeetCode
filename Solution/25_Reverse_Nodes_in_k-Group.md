## Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.

*k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes, in the end, should remain as it is.

**Follow up:**

- Could you solve the problem in `O(1)` extra memory space?
- You may not alter the values in the list's nodes, only nodes itself may be changed.

**Example 1:**

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Example 2:**

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

**Example 3:**

```
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
```

**Example 4:**

```
Input: head = [1], k = 1
Output: [1]
```

**Constraints:**

- The number of nodes in the list is in the range `sz`.
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`

#### 判断 + 链表翻转：

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
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode* per = tail->next;
        ListNode* cur = head;
        while(per != tail){
            ListNode* temp = cur->next;
            cur->next = per;
            per = cur;
            cur = temp;
        }
        return make_pair(tail, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* pre = ans;
        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return ans->next;
                }
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> result = reverseList(head, tail);
            head = result.first;
            tail = result.second;
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return ans->next;
    }
};
```

