## Design Circular Queue

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the `MyCircularQueue` class:

- `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.
- `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.
- `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.
- `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the operation is successful.
- `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is successful.
- `boolean isEmpty()` Checks whether the circular queue is empty or not.
- `boolean isFull()` Checks whether the circular queue is full or not.

**Example 1:**

```
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
```

**Constraints:**

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `3000` calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and `isFull`.

#### 使用数组模拟循环队列：

需要定义四个属性：

- 用于存储循环队列数据的数组 queue
- 循环队列的队首 head
- 循环队列的长度 len
- 循环队列的容量 capacity

通过循环队列的队首 head 和长度 len 以及容量 capacity 可以计算出循环队列的队尾 tail：

- tail = (head + len - 1) % capacity

其他就是细节问题：边界情况判断和是否存在数据的判断

```c++
class MyCircularQueue {
private:
    vector<int> queue;
    int head = 0, len = 0, capacity = 0;
public:
    MyCircularQueue(int k) {
        head = 0;
        len = 0;
        capacity = k;
        queue.assign(k, 0);
    }
    
    bool enQueue(int value) {
        if(len < capacity){
            int cur = (head + len) % capacity;
            queue[cur] = value;
            len++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(len > 0){
            head = (head + 1) % capacity;
            len--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(len > 0)
            return queue[head];
        return -1;
    }
    
    int Rear() {
        if(len > 0){
            int tail = (head + len - 1) % capacity;
            return queue[tail];
        }
        return -1;
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```

