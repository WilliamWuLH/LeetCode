## Perfect Squares

Given a positive integer *n*, find the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to *n*.

**Example 1:**

```
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
```

**Example 2:**

```
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

#### 动态规划：

```c++
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i] = i;
            int j = 1;
            while( i-j*j >= 0){
                dp[i] = min(dp[i], dp[i-j*j]+1);
                j++;
            }
        }
        return dp[n];
    }
};
```

