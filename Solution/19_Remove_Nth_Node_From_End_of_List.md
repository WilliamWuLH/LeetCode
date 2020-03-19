## Remove Nth Node From End of List

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

