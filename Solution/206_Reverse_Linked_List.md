## Reverse Linked List

Reverse a singly linked list.

**Example:**

```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

**Follow up:**

A linked list can be reversed either iteratively or recursively. Could you implement both?

#### 保存每一个链表结点：

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<ListNode*> nodes;
        while(head != NULL){
            nodes.push_back(head);
            head = head->next;
        }
        for(int i=nodes.size()-1; i>0; i--){
            nodes[i]->next = nodes[i-1];
        }
        nodes[0]->next = NULL;
        return nodes[nodes.size()-1];
    }
};
```

#### 双指针：

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
    ListNode* reverseList(ListNode* head) {
        ListNode* per = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* temp = cur->next;
            cur->next = per;
            per = cur;
            cur = temp;
        }
        return per;
    }
};
```

