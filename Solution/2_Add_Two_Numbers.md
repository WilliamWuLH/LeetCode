## Add Two Numbers

#### 考虑多种情况：

​		链表可能不一样长，最后一位也可能会进位（最后需要再判断进位carry）。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* index = new ListNode();
        ListNode* ans = index;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            index->next = new ListNode();
            index = index->next;
            int sum = l1->val + l2->val + carry;
            if(sum>9){
                sum = sum - 10;
                carry = 1;
            }
            else
                carry = 0;
            index->val = sum;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 != NULL)
            l1 = l2;
        while(l1 != NULL){
            index->next = new ListNode();
            index = index->next;            
            int sum = l1->val + carry;
            if(sum>9){
                sum = sum - 10;
                carry = 1;
            }
            else
                carry = 0;
            index->val = sum;
            l1 = l1->next;
        }
        if(carry == 1){
            index->next = new ListNode();
            index = index->next;
            index->val = carry;
        }
        return ans->next;
    }
};
```

