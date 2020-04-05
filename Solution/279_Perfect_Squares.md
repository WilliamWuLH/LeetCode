## Perfect Squares

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

