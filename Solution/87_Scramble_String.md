## Scramble String

#### 区间DP：

​			确定字符串 s1 的起点，再确定字符串 s2 的起点，还有旋转的字符串长度，进行动态规划。

```c++
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1 != l2)
            return false;
        vector<vector<vector<bool>>> dp(l1, vector<vector<bool>>(l2, vector<bool>(l1+1, 0)));
        for(int len = 1; len <= l1; len++){
            for(int i=0; i<=l1-len; i++){
                for(int j=0; j<=l2-len; j++){
                    if(len == 1)
                        dp[i][j][len] = (s1[i] == s2[j]);
                    else{
                        for(int k=1; k<len; k++){
                            dp[i][j][len] = (dp[i][j][k] && dp[i+k][j+k][len-k]) ||
                                            (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                            if(dp[i][j][len])
                                break;                                
                        }
                    }
                }
            }
        }
        return dp[0][0][l1];
    }
};
```

