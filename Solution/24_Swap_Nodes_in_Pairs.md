## Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may **not** modify the values in the list's nodes. Only nodes itself may be changed.

**Example 1:**

```
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```

**Example 2:**

```
Input: head = []
Output: []
```

**Example 3:**

```
Input: head = [1]
Output: [1]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

#### 简单的指针操作：

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = new ListNode;
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* n = head->next;
        ListNode* pre = ans;
        while(n != NULL){
            pre->next = n;
            ListNode* nn = n->next;
            n->next = head;
            head->next = nn;
            pre = head;
            if(head->next != NULL)
                head = head->next;
            n = head->next;
        }
        return ans->next;
    }
};
```

