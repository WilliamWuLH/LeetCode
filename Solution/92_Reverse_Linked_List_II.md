## Reverse Linked List II

#### 分类讨论 + 遍历过程中进行反转（实现 one-pass：一次遍历）：

​		使用过程变量记录需要反转的链表的头部和尾部，根据总链表的长度进行分类讨论，属于不同长度区间的结点需要进行不同的操作。

​		难点：需要判断 m == n 的情况。

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n)
            return head;
        ListNode ans;
        ans.next = head;
        ListNode* pre = &ans;
        ListNode* mm = pre;
        ListNode* ml = head; 
        int len = 0;
        while(head != NULL){
            len++;
            if(len < m){
                pre = head;
                head = head->next;
            }
            else if(len == m){
                ml = head;
                mm = pre;
                pre = head;
                head = head->next;
            }
            else if(len > m && len < n){
                ListNode* head_next = head->next;
                head->next = pre;
                pre = head;
                head = head_next;
            }
            else if(len == n){
                ListNode* head_next = head->next;
                head->next = pre;
                mm->next = head;
                ml->next = head_next;
                break;
            }
        }
        return ans.next;
    }
};
```

