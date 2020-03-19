## Merge Two Sorted Lists

#### 简单归并：

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans;
        ListNode* index;
        index = &ans;
        ans.next = NULL;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                index->next = l1;
                l1 = l1->next;
            }
            else{
                index->next = l2;
                l2 = l2->next;
            }
            index = index->next;
        }
        if(l1 == NULL && l2 != NULL)
            index->next = l2;
        if(l1 != NULL && l2 == NULL)
            index->next = l1;
        return ans.next;
    }
};
```

