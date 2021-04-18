## Remove Nth Node From End of List

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Follow up:** Could you do this in one pass?

**Example 1:**

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**

```
Input: head = [1], n = 1
Output: []
```

**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]
```

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

#### 2021.4.18 再回首

#### 双指针 + 判断：

​		两个指针之间相隔 n，当前面的指针到达链表的结尾时，后面的指针指向的结点就是要删除的结点，也就是链表的倒数第 N 个结点。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *a = head, *b = head, *pre = b;
        while(a != nullptr && n--)
            a = a->next;
        if(a == nullptr)
            return head->next;
        while(a != nullptr){
            a = a->next;
            pre = b;
            b = b->next;
        }
        pre->next = b->next;
        return head;
    }
};
```



#### 开 vector 保存链表各个 node：

​		特殊情况：删去链表的第一个和最后一个。

​				第一个：直接返回链表的第二个 node，其为新的链表头。

​				最后一个：在 vector 的最后再存入一个 NULL，就可以应用到通用公式。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node;
        int count = 0;
        node.push_back(head);
        ListNode* index = head;
        while(index->next != NULL){
            index = index->next;
            count++;
            node.push_back(index);
        }
        node.push_back(NULL);
        if(count == n-1)
            return node[1];
        node[count-n]->next = node[count-n+2];
        return node[0];
    }
};
```

