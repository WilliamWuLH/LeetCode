## Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

**Notice** that you **should not modify** the linked list.

**Example 1:**

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

**Example 2:**

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

**Example 3:**

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

**Constraints:**

- The number of the nodes in the list is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- `pos` is `-1` or a **valid index** in the linked-list.

**Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?

#### 方法一：保存链表结点

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
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode *> hash;
        while(head != NULL){
            if(find(hash.begin(), hash.end(), head) != hash.end())
                return head;
            else
                hash.push_back(head);
            head = head->next;
        }
        return NULL;
    }
};
```

#### 方法二：Floyd 算法 + 双指针（快慢指针）

​		慢指针一次走一步，快指针一次走两步。

​		首先需要判断快指针会不会走到链表的结尾，即会不会遇到 NULL，以此判断链表是否有环。

​		如果快指针和慢指针相遇了，则说明链表有环，接下来就是数学推导了：

​		假设链表中不成环（链）的长度为 L，环的长度为 C，在第一次相遇时慢指针走的长度为 S，快指针走的长度为 F。假设其中慢指针在环中走的长度为 Cs，快指针在环中走的长度为 Cf。可以得出以下结论：

- F = 2 S            F = L + Cf            S = L + Cs            Cf = C + Cs

- 2 ( L + Cs ) = L + Cf            L + 2 Cs = Cf            L + 2 Cs = C + Cs

- L = C - Cs

  所以，慢指针走完剩下的环的长度等于从链表开头走到环的起点的长度，由此可以得到环的开始结点。

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
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while(1){
            if(fast == NULL || fast->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
```

