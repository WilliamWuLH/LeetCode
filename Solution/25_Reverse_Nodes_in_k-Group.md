## Reverse Nodes in k-Group

#### 判断 + 链表翻转：

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
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode* per = tail->next;
        ListNode* cur = head;
        while(per != tail){
            ListNode* temp = cur->next;
            cur->next = per;
            per = cur;
            cur = temp;
        }
        return make_pair(tail, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* pre = ans;
        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return ans->next;
                }
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> result = reverseList(head, tail);
            head = result.first;
            tail = result.second;
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return ans->next;
    }
};
```

