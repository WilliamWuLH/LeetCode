## Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only *once*.

**Example 1:**

```
Input: 1->1->2
Output: 1->2
```

**Example 2:**

```
Input: 1->1->2->3->3
Output: 1->2->3
```

#### 遍历链表 + 判断：

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        while(head != NULL && head->next != NULL){
            if(head->val == head->next->val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return ans;
    }
};
```

