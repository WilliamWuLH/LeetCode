## Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:

- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

**Notes:**

- You must use **only** standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

**Follow-up:** Can you implement the queue such that each operation is **[amortized](https://en.wikipedia.org/wiki/Amortized_analysis)** `O(1)` time complexity? In other words, performing `n` operations will take overall `O(n)` time even if one of those operations may take longer.

**Example 1:**

```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

**Constraints:**

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.

#### 用栈实现队列：

​		通过 LIFO 实现 FIFO，其实就是把输出的顺序倒转过来，详见代码。

具体实现：

- 一个栈作为输入，如栈 s1 作为输入栈。
- 一个栈作为输出，如栈 s2 作为输出栈。
- 在实现队列输入时，只需要不断地输入到 s1 输入栈中。
- 在实现队列输出时，首先判断输出栈 s2 是否为空，如果输出栈 s2 为空，则需要把输入栈 s1 的元素搬到输出栈 s2 中，因为输入栈 s1 的元素顺序为 LIFO，所以输入栈 s1 中元素弹栈再压栈到输出栈 s2 中时，输出栈 s2 的元素顺序就为 FIFO 了，所以按照输出栈 s2 的弹栈顺序输出就是队列的输出顺序。

```c++
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty())
            front = x;
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                int temp = s1.top();
                s2.push(temp);
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;        
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty())
            return s2.top();
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

