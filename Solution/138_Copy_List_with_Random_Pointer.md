## Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list.

The Linked List is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) where random pointer points to, or `null` if it does not point to any node.

**Example 1:**

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**Example 2:**

```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

**Example 3:**

```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

**Example 4:**

```
Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
```

**Constraints:**

- `-10000 <= Node.val <= 10000`
- `Node.random` is null or pointing to a node in the linked list.
- The number of nodes will not exceed 1000.

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

