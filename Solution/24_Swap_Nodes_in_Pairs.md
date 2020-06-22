## Swap Nodes in Pairs

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

