## Odd Even Linked List

#### 把所有的奇数位置节点和偶数位置节点分别排在一起：

​		很直接，遍历整个链表，按原链表顺序把处于奇数位置的节点依次连接，把处于偶数位置的节点依次连接，然后把奇数位置节点的链表和偶数位置节点的链表相连接。

​		实现起来就是按照原链表顺序依次遍历每一个节点，把节点的 next 指向它的下一个节点的下一个节点，也就是 next 的 next。

​		重点难点：把 head == nullptr 列为特殊情况，同时链表节点个数的奇偶也会影响最后结果，如果链表的节点数目为偶数个则需要提前结束遍历，因为奇数位置节点的最后一个节点其实是原链表的倒数第二个节点。

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode *ohead = head->next, *cur = head;
        int count = 0;
        while(cur->next != nullptr){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            count++;
            if(count % 2 && temp->next == nullptr)
                break;
            cur = temp;
        }
        cur->next = ohead;
        return head;
    }
};
```

