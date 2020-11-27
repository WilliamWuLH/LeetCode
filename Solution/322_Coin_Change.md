## Coin Change

You are given coins of different denominations and a total amount of money *amount*. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Example 2:**

```
Input: coins = [2], amount = 3
Output: -1
```

**Example 3:**

```
Input: coins = [1], amount = 0
Output: 0
```

**Example 4:**

```
Input: coins = [1], amount = 1
Output: 1
```

**Example 5:**

```
Input: coins = [1], amount = 2
Output: 2
```

**Constraints:**

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`

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

