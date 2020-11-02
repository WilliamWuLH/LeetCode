## Copy List with Random Pointer

#### DFS + 哈希表：

​		把带随机指针的链表看做图，使用图的深度优先搜索进行遍历深拷贝，为了防止由于图中有环而出现无限循环，使用哈希表记录已经访问过的结点，哈希表的键为原链表的结点，值为深拷贝新生成的结点。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> hash;
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        if(hash.count(head))
            return hash[head];
        Node* cur = new Node(head->val);
        hash[head] = cur;
        cur->next = copyRandomList(head->next);
        cur->random = copyRandomList(head->random);
        return cur;
    }
};
```

