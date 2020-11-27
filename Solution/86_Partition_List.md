## Partition List

Given a linked list and a value *x*, partition it such that all nodes less than *x* come before nodes greater than or equal to *x*.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```

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

