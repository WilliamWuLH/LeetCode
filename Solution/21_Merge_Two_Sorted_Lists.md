## Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new **sorted** list. The new list should be made by splicing together the nodes of the first two lists.

**Example 1:**

```
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```
Input: l1 = [], l2 = []
Output: []
```

**Example 3:**

```
Input: l1 = [], l2 = [0]
Output: [0]
```

**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `l1` and `l2` are sorted in **non-decreasing** order.

#### 简单归并：

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans;
        ListNode* index;
        index = &ans;
        ans.next = NULL;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                index->next = l1;
                l1 = l1->next;
            }
            else{
                index->next = l2;
                l2 = l2->next;
            }
            index = index->next;
        }
        if(l1 == NULL && l2 != NULL)
            index->next = l2;
        if(l1 != NULL && l2 == NULL)
            index->next = l1;
        return ans.next;
    }
};
```

