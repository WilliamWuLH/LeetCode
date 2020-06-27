## Rotate List

#### 链表成环 + 双指针：

​		首先，将链表的尾部和头部连接在一起，并且统计链表的结点个数。

​		然后，通过结点个数和移动的位置数目计算出应该在什么地方断开链表。

​		使用双指针是为了在到达正确位置的同时可以取到上一个结点的指针。

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* index = head;
        ListNode* pre = index;
        int num = 0;
        while(index != NULL){
            pre = index;
            index = index->next;
            num++;
        }
        pre->next = head;
        k %= num;
        index = head;
        while(num-k){
            pre = index;
            index = index->next;
            num--;
        }
        pre->next = NULL;
        return index;
    }
};
```

