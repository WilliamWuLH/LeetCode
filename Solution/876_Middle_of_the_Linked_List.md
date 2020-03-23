## Middle of the Linked List

#### 遍历链表：

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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> ans;
        int count = 0;
        while(head != NULL){
            ans.push_back(head);
            count++;
            head = head->next;
        }
        return ans[count/2];
    }
};
```

