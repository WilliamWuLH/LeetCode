## Palindrome Linked List

#### 双指针（快慢指针）+ 反转后半部分链表：

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = NULL;
        while(slow != NULL){
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = pre;
            pre = temp;
        }
        fast = head;
        while(pre != NULL){
            if(fast->val != pre->val)
                return false;
            fast = fast->next;
            pre = pre->next;
        }
        return true;
    }
};
```

