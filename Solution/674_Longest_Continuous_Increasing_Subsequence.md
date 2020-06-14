## Longest Continuous Increasing Subsequence

#### 遍历 + 判断：

```c++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            if(i == 0 || nums[i-1] >= nums[i])
                count = 1;
            else
                count++;
            ans = max(ans, count);
        }
        return ans;
    }
};
```

