## Coin Change

#### 动态规划：

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            dp[i] = amount+1;
            int len = coins.size();
            while(len){
                if(i - coins[len-1] >= 0)
                    dp[i] = min(dp[i-coins[len-1]]+1, dp[i]);
                len--;
            }
        }
        if(dp[amount] == amount+1)
            return -1;
        else
            return dp[amount];
    }
};
```

