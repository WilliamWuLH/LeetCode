## Best Time to Buy and Sell Stock with Cooldown

#### 动态规划：

​		每天判断买股票和卖股票两种情况，答案为最后一天不持有股票的情况。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1)
            return 0;
        int dp[len][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1; i<len; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], i > 1 ? dp[i-2][0]-prices[i] : 0-prices[i]);
        }
        return dp[len-1][0];
    }
};
```

