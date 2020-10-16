## Reorder List

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

