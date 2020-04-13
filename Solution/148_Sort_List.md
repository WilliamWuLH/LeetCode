## Sort List

#### 归并排序 + 快慢指针：

​		快慢指针：找出链表的中间位置。

​		归并排序：将两个链表按顺序进行合并。

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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* mid;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next!= NULL){
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode head;
        ListNode* ans = &head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                ans->next = l1;
                l1 = l1->next;
            }
            else{
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        ans->next = l1 == NULL ? l2 : l1;
        return head.next;
    }
};
```

