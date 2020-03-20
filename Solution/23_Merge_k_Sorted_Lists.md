## Merge k Sorted Lists

#### 分治法（类似于归并排序）：

​			将等待合并的链表集合先进行划分，把链表集合分为两个部分，对两个部分进行讨论。

​			如果此时两个部分的链表个数仍然大于 1，则要继续划分，将一个部分继续划分为两个部分，直到每个部分的链表个数为 1 时，返回该链表。

​			由于每次都进行两两划分，所以最后可以把每个部分都视为是两个链表的合并，把多链表的问题分治为两链表的问题。

​			每个大块会划分为两个小块，两个小块会返回一个有序链表，大块的事情就是把这两个小块的链表进行合并，得到一条合并的有序链表，大块将返回这条链表，这条链表将给更大的块去进行合并。

​			将多链表的合并进行逐层划分，变为多个两链表的合并，类似于归并排序的思想。

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0)
            return NULL;
        ListNode* ans = mergesort(lists,0,size-1);
        return ans;
    }
    ListNode* mergesort(vector<ListNode*>& lists,int left,int right){
        if(left == right)
            return lists[left];
        int mid = (left + right)/2;
        ListNode* l1 = mergesort(lists,left,mid);
        ListNode* l2 = mergesort(lists,mid+1,right);
        ListNode* lm = merge(l1,l2);
        return lm;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
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

