## Palindromic Substrings

#### 动态规划：

```c++
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int dp[len+1][len+1];
        memset(dp, 0, (len+1)*(len+1)*sizeof(int));
        int ans = 0;
        for(int i=0; i<len; i++){
            for(int j=0; j<=i; j++){
                if(s[i] == s[j] && (i-j < 2 || dp[j+1][i-1] == 1)){
                    dp[j][i] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

#### 中心扩展：

```c++
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int ans = 0;
        for(int i=0; i<2*len-1; i++){
            int left = i/2;
            int right = left + i%2;
            while(left >= 0 && right < len && s[left] == s[right]){
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};
```

#### 马拉车算法：