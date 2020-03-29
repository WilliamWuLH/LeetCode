## Linked List Cycle II

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

