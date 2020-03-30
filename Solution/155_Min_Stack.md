## Min Stack

#### 存储最小值 + 不断更新最小值：

```c++
class MinStack {
private:
    stack<pair<int,int>> minstack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(minstack.empty()){
            pair<int,int> temp(x,x);
            minstack.push(temp);
        }
        else{
            int cur = min(minstack.top().first, x);
            pair<int,int> temp(cur,x);
            minstack.push(temp);
        }
    }
    
    void pop() {
        minstack.pop();
    }
    
    int top() {
        return minstack.top().second;
    }
    
    int getMin() {
        return minstack.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

#### 使用辅助栈存储最小值：

```c++
class MinStack {
private:
    stack<int> minstack;
    stack<int> numstack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        numstack.push(x);
        if(minstack.empty())
            minstack.push(x);
        else{
            int temp = min(minstack.top(), x);
            minstack.push(temp);
        }
    }
    
    void pop() {
        numstack.pop();
        minstack.pop();
    }
    
    int top() {
        return numstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

