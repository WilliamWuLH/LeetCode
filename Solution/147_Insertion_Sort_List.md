## Insertion Sort List

 Sort a linked list using insertion sort. 

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list

**Algorithm of Insertion Sort:**

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.


**Example 1:**

```
Input: 4->2->1->3
Output: 1->2->3->4
```

**Example 2:**

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```

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

