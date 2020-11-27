##  Longest Palindromic Substring 

Given a string `s`, return *the longest palindromic substring* in `s`.

**Example 1:**

```
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

**Example 2:**

```
Input: s = "cbbd"
Output: "bb"
```

**Example 3:**

```
Input: s = "a"
Output: "a"
```

**Example 4:**

```
Input: s = "ac"
Output: "a"
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consist of only digits and English letters (lower-case and/or upper-case),

#### 动态规划：

​		初始化长度为 1 的回文子串：dp[ i ] [ i ]；

​		初始化长度为 2 的回文子串：

​				需要满足：s [ i ] = s [ i+1 ]，dp[ i ] [ i+1 ] 就为 1；

​		循环判断长度从 3 到 s.length() 的回文子串：设此时回文子串的长度为 n

​				循环回文子串的开始位置：i，从 0 开始，到 s.length() - n 结束。

​				需要满足：s [ i ] = s [ i+n-1 ]；

​				并且从 i+1 开始，到 i+n-2 结束的子串为回文子串，即 dp[ i+1 ] [ i+n-2 ] = 1。

​		循环的过程中不断更新回文子串的最大长度和开始位置。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0 || len == 1)
            return s;
        int start = 0,maxlen = 1;
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0;i<len;i++){
            dp[i][i] = 1;
            if(i < len-1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                maxlen = 2;
                start = i;
            }
        }
        for(int n = 3;n <= len;n++){
            for(int i=0;i<=len-n;i++){
                if(s[i] == s[i+n-1] && dp[i+1][i+n-2] == 1){
                    dp[i][i+n-1] = 1;
                    if(maxlen < n){
                        start = i;
                        maxlen = n;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
```



#### 中心扩展：

​		把字符串的**某个字符**，或者是**某两个相邻字符**之间的位置作为中心；

​		以中心为基准，向两边扩展，如果两边相同，则为回文子串。

​		循环遍历字符串中的中心位置，讨论以此为中心的回文子串。

​		不断更新回文子串的最大长度和开始位置。

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1)
            return s;
        int start = 0,maxlen = 1;
        for(int i=0;i<len;i++){
            int begin = i,end = i;
            while(begin-1 >= 0 && end+1 < len){
                if(s[begin-1] == s[end+1]){
                    begin = begin -1;
                    end = end + 1;
                    if(maxlen < (end - begin + 1)){
                        maxlen = end - begin + 1;
                        start = begin;
                    }
                }
                else
                    break;
            }
            begin = i;
            end = i+1;
            while(begin >= 0 && end < len){
                if(s[begin] == s[end]){
                    if(maxlen < (end - begin + 1)){
                        maxlen = end - begin + 1;
                        start = begin;
                    }
                    begin -= 1;
                    end += 1;
                }
                else
                    break;
            }
        }
        return s.substr(start,maxlen);
    }
};
```