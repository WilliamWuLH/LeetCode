## Remove Linked List Elements

Remove all elements from a linked list of integers that have value **val**.

**Example:**

```
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
```

#### 前后指针，按顺序遍历链表：

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode;
        ListNode* pre = ans;
        ans->next = head;
        while(head != NULL){
            if(head->val == val)
                pre->next = head->next;
            else
                pre = head;
            head = head->next;
        }
        return ans->next;
    }
};
```

