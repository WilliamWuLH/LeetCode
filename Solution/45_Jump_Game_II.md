## Jump Game II

#### 贪心算法：

​		正向查找可到达的最大位置。

​		我们维护当前能够到达的最大下标位置，记为边界。我们从左到右遍历数组，到达边界时，更新边界并将跳跃次数增加 1。

​		在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。如果访问最后一个元素，在边界正好为最后一个位置的情况下，我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxpos = 0, edge = 0, step = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(maxpos >= i){
                maxpos = max(maxpos, i+nums[i]);
                if(i == edge){
                    edge = maxpos;
                    step++;
                }
            }
        }
        return step;
    }
};
```

