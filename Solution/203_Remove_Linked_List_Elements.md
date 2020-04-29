## Remove Linked List Elements

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

