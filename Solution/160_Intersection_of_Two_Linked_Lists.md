## Intersection of Two Linked Lists

#### 双指针 + 数学推导：

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * posA = headA;
        ListNode * posB = headB;
        while(posA != posB){
            posA = posA == NULL ? headA : posA->next;
            posB = posB == NULL ? headB : posB->next;
        }
        return posA;
    }
};
```

