## Delete Node in a Linked List

#### 从前往后逐个替换结点，去掉最后一个结点：

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
    void deleteNode(ListNode* node) {
        while(node->next){
            node->val = node->next->val;
            if(node->next->next == NULL){
                node->next = NULL;
                return;
            }
            node = node->next;
        }
    }
};
```

