## Sliding Window Maximum

#### 双端队列：

​		为什么选择双端队列？

​		既可以弹出队首元素，也可以弹出队尾元素，也可以在队尾插入元素，也可以访问队首元素。

​		在双端队列中维持一个数组值单调递减的队列，队列中的元素必须都在窗口中，并且队首元素就是最大值，第二个就是第二大的值，以此类推。

​		每次来一个元素，判断这个元素应该在这个双端队列的什么位置，从双端队列的队尾开始判断，比它小的都要弹出队列，直到找到比它大的或者是队列为空了，把此时的这个元素插入队列中。

​		并且需要判断此时的队首是否还在新窗口中，即此时的最大值是否还合法，不合法（不在窗口中）就必须弹出。

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int len = nums.size();
        for(int i=0; i<len; i++){
            while(!dq.empty()){
                if(dq.front() <= i-k)
                    dq.pop_front();
                else if(nums[ dq.back() ] < nums[i])
                    dq.pop_back();
                else
                    break;
            }
            dq.push_back(i);
            if(i+1 >= k)
                ans.push_back(nums[ dq.front() ]);
        }
        return ans;
    }
};
```

