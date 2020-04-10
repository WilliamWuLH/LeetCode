## Shortest Unsorted Continuous Subarray

#### 排序找不同：

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy;
        copy = nums;
        sort(copy.begin(), copy.end());
        int head = 0, tail = nums.size()-1;
        while(head <= tail && copy[head] == nums[head])
            head++;
        while(head <= tail && copy[tail] == nums[tail])
            tail--;
        return tail-head+1;
    }
};
```

