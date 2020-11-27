## Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only *distinct* numbers from the original list.

Return the linked list sorted as well.

**Example 1:**

```
Input: 1->2->3->3->4->4->5
Output: 1->2->5
```

**Example 2:**

```
Input: 1->1->1->2->3
Output: 2->3
```

#### 双指针 + 一状态：

​		写完之后看看题解怎么都是三指针，可能是一样的思想吧。

​		双指针，一个是记录**当前最后一个满足条件**的链表结点，一个是**遍历**整个链表用的。

​		一状态是用于判断当两个结点值不同时，前面这个链表结点是否加入答案中，即是否满足条件。

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
        ListNode* ans = new ListNode;
        ListNode* pre = ans;
        int flag = 0;
        while(head != NULL && head->next != NULL){
            if(head->val == head->next->val){
                head = head->next;
                flag = 1;
            }
            else if(flag == 1 && head->val != head->next->val){
                head = head->next;
                flag = 0;
            }
            else if(flag == 0 && head->val != head->next->val){
                cout <<head->val <<"  ";
                pre->next = head;
                pre = pre->next;
                head = head->next;
                flag = 0;
            }
        }
        if(head != NULL && flag == 0)
            pre->next = head;
        else
            pre->next = NULL;
        return ans->next;
    }
};
```

