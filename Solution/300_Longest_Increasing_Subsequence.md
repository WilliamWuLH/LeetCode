## Longest Increasing Subsequence

#### 动态规划：

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int dp[len], ans = 0;
        for(int i=0; i<len; i++){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

#### 动态规划 + 二分查找：

```c++

```

