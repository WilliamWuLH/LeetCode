## Palindromic Substrings

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

**Example 1:**

```
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

**Example 2:**

```
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

**Note:**

1. The input string length won't exceed 1000.

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