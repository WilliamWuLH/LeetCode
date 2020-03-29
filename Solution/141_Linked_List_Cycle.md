## Linked List Cycle

#### 方法一：

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
    bool hasCycle(ListNode *head) {
        while(head != NULL){
            if(head->val == -50505050)
                return true;
            else
                head->val = -50505050;
            head = head->next;
        }
        return false;
    }
};
```

#### 方法二：

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
    bool hasCycle(ListNode *head) {
        vector<ListNode *> hash;
        while(head != NULL){
            if(find(hash.begin(), hash.end(), head) != hash.end())
                return true;
            else
                hash.push_back(head);
            head = head->next;
        }
        return false;
    }
};
```

