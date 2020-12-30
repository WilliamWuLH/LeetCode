## Last Stone Weight

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two **heaviest** stones and smash them together. Suppose the stones have weights `x` and `y` with `x <= y`. The result of this smash is:

- If `x == y`, both stones are totally destroyed;
- If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.

At the end, there is at most 1 stone left. Return the weight of this stone (or 0 if there are no stones left.)

**Example 1:**

```
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
```

**Note:**

1. `1 <= stones.length <= 30`
2. `1 <= stones[i] <= 1000`

#### 优先队列：

​		使用优先队列先对所有石头进行排序并保持有序性，然后模拟整个取出石头并且处理的过程，直到最后没有石头或者只剩下一个石头的时候结束。

```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &s : stones)
            pq.push(s);
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x < y)
                pq.push(y - x);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
```

#### 最大堆：

​		首先，手写一个最大堆函数把 stones 组织成一个最大堆。

​		接着，模拟整个取出石头并且处理的过程：

- 取出此时重量最大的石头：y = stones[0]，在最大堆中的操作相当于把根节点（堆顶元素）删除。
- 接着就可以判断这个最大重量的石头 y 和第二重的石头重量（此时为 stones[0]）是否相等：
  - 如果相等（y == stones[0]）则将一起完全粉碎，在最大堆中的操作相当于继续把根节点（堆顶元素）删除。
  - 如果重量不相等（y != stones[0]），则可以把根节点（堆顶元素）的值更改为石头新重量 y - stones[0]，并且需要调整整棵树到满足最大堆。
- 整个过程持续到最大堆中没有元素或者只剩一个元素时结束。

```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        for(int i = n/2-1; i >= 0; i--)
            max_heap(stones, i, n);
        while(n > 1){
            int y = stones[0];
            stones[0] = stones[--n];
            max_heap(stones, 0, n);
            if(y == stones[0]){
                stones[0] = stones[--n];
                max_heap(stones, 0, n);
            }
            else{
                stones[0] = y - stones[0];
                max_heap(stones, 0, n);
            }
        }
        return n == 0 ? 0 : stones[0];
    }
    void max_heap(vector<int>& stones, int start, int end){
        int father = start;
        int child = father*2 + 1;
        while(child < end){
            if(child + 1 < end && stones[child] < stones[child + 1])
                child++;
            if(stones[father] >= stones[child])
                break;
            else{
                int temp = stones[father];
                stones[father] = stones[child];
                stones[child] = temp;
                father = child;
                child = father*2 + 1;
            }
        }
        return;
    }
};
```

