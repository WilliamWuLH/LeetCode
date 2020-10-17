## Implement Stack using Queues

#### 使用两个队列实现一个栈：

​		其实就是维持一个 LIFO 的顺序。先要准备好两个空的队列 q1 和 q2。

##### 元素个数：1

- 此时只有一个元素，将元素 a 存在队列 q1 中，队列 q1 的 pop 顺序就是栈的出栈顺序。
- 此时队列 q2 为空。

##### 元素个数：2

- 再 push 一个元素 b，因为是 LIFO 的顺序，所以元素 b 应该在队列的首部，所以将元素 b 存在队列 q2 中。
- 再将队列 q1 中的所有元素按顺序 pop 出来再 push 到队列 q2 中，队列 q1 的顺序就是出栈顺序，所以此时队列 q2 的顺序就是整个栈的出栈顺序。
- 此时队列 q1 为空。

##### 元素个数：3

- 再 push 一个元素 c，维持 LIFO 的顺序，因为此时队列 q1 为空，所以将元素 c 存在队列 q1 的队首。
- 将队列 q2 的所有元素依次 pop 再 push 到队列 q1 中，顺序就是栈的顺序，所以此时队列 q1 的 pop 顺序也就是整个栈的出栈顺序。
- 此时队列 q2 为空。

##### 元素个数：n

- 以此类推，当 push 一个元素 x 时，将元素 x 存到此时为空的队列的队首。
- 此时另一个不为空的队列维持的顺序就是之前栈的顺序。
- 将这个不为空的队列依次转存到这个以元素 x 为队首的队列中，依然维持着栈的顺序。
- 之前不为空的队列在进行转存之后就变成了空的队列，可以用于下一个元素的 push 使用。

```c++
class MyStack {
private:
    queue<int> a;
    queue<int> b;
public:
    /** Initialize your data structure here. */
    MyStack() {
        a = queue<int>();
        b = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(a.empty()){
            a.push(x);
            while(!b.empty()){
                int temp = b.front();
                b.pop();
                a.push(temp);
            }
        }
        else if(b.empty()){
            b.push(x);
            while(!a.empty()){
                int temp = a.front();
                a.pop();
                b.push(temp);
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int p = 0;
        if(!a.empty()){
            p = a.front();
            a.pop();
        }
        else if(!b.empty()){
            p = b.front();
            b.pop();
        }
        return p;
    }
    
    /** Get the top element. */
    int top() {
        int t = 0;
        if(!a.empty())
            t = a.front();
        else if(!b.empty())
            t = b.front();
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        bool ans = true;
        if(a.empty() && b.empty())
            ans = true;
        else
            ans = false;
        return ans;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

