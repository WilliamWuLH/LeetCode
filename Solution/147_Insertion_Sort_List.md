## Insertion Sort List

#### 对链表进行插入排序：

​		首先需要了解什么是插入排序，然后就不难了。详见代码：

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode ans;
        ans.next = head;
        ListNode* pre = &ans;
        while(head != NULL && head->next != NULL){
            if(head->next->val >= head->val){
                head = head->next;
                continue;
            }
            pre = &ans;
            while(pre->next->val < head->next->val)
                pre = pre->next;
            ListNode* cur = head->next;
            head->next = head->next->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        return ans.next;
    }
};
```

