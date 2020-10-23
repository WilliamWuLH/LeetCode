## Implement Queue using Stacks

#### 用栈实现队列：

​		通过 LIFO 实现 FIFO，其实就是把输出的顺序倒转过来，详见代码。

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

