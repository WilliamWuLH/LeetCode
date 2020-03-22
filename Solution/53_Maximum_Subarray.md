## Maximum Subarray

#### 动态规划：

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        int len = nums.size();
        int ans = nums[0];
        dp.push_back(nums[0]);
        for(int i=1; i<len; i++){
            dp.push_back(nums[i]);
            if(dp[i-1] + nums[i] > dp[i])
                dp[i] = dp[i-1] + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

