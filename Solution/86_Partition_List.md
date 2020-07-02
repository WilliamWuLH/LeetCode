## Partition List

#### 双链表 + 合并链表：

​			一次遍历。

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = new ListNode;
        ListNode* high = new ListNode;
        ListNode* l = low;
        ListNode* h = high;
        while(head != NULL){
            if(head->val < x){
                l->next = head;
                l = l->next;
            }
            else{
                h->next = head;
                h = h->next;
            }
            head = head->next;
        }
        h->next = NULL;
        l->next = high->next;
        return low->next;
    }
};
```

