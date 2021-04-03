## Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

**Example 1:**

```
Input: 1->2
Output: false
```

**Example 2:**

```
Input: 1->2->2->1
Output: true
```

**Follow up:**
Could you do it in O(n) time and O(1) space?

#### 2021.4.3 反思录

​		差不多快一个月没有写 leetcode 了，我连快慢指针和反转链表都不会写了......

#### 双指针（快慢指针）+ 反转后半部分链表：

​		所谓双指针中的快慢指针，肯定是拿快指针作为判断和决定是否遍历结束的条件，因为慢指针相当于在走快指针走过的路。

​		所以我们讨论快指针，首先需要判断当前快指针是不是为空，因为我们可能遍历的是一个空链表，快指针 fast 初始化为 head，空链表 head 为 NULL，没有下一个结点了，所以如果第一步直接讨论快指针的下一个结点即 fast->next 可能会出错。当我们确定快指针 fast 不为空 NULL 时，我们才继续讨论快指针的下一个结点 fast->next，我们也需要确保 fast->next 不是 NULL，因为我们的快指针 fast 下一次取值是 fast->next->next（不管 fast->next->next 是不是为 NULL），首先必须是 fast->next 不为 NULL 才可能存在 fast->next->next。

​		综上，在进行快慢指针的移动时，需要判断的主要就两个地方：fast != NULL 和 fast->next != NULL。

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = NULL;
        while(slow != NULL){
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = pre;
            pre = temp;
        }
        fast = head;
        while(pre != NULL){
            if(fast->val != pre->val)
                return false;
            fast = fast->next;
            pre = pre->next;
        }
        return true;
    }
};
```

