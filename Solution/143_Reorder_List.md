## Reorder List

Given a singly linked list *L*: *L*0→*L*1→…→*L**n*-1→*L*n,
reorder it to: *L*0→*L**n*→*L*1→*L**n*-1→*L*2→*L**n*-2→…

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

**Example 1:**

```
Given 1->2->3->4, reorder it to 1->4->2->3.
```

**Example 2:**

```
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
```

#### 快慢指针 + 反转数组：

​		通过快慢指针找到链表的中间节点，再将后面的链表进行反转，最后重新排序。

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
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        pre = slow;
        slow = slow->next;
        pre->next = NULL;
        while(slow != NULL){
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        while(head != NULL && pre != NULL){
            ListNode* temp = head->next;
            head->next = pre;
            head = pre;
            pre = temp;
        }
    }
};
```

