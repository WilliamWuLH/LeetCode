## Sort List

Given the `head` of a linked list, return *the list after sorting it in **ascending order***.

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

**Example 1:**

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

**Example 3:**

```
Input: head = []
Output: []
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

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

