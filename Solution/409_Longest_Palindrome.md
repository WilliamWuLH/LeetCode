## Longest Palindrome 

#### 构建字母表 + 统计个数：

​		统计字符串里面的字母个数。

​		字母个数为偶数，直接加入答案。

​		字母个数为奇数，个数减一后加入答案，在最后的答案中再加入中间的 “ 1 ”。

```c++
class Solution {
public:
    int longestPalindrome(string s) {
        int low_count[26];
        int up_count[26];
        int mid = 0,ans = 0;
        int len = s.length();
        for(int i=0;i<26;i++){
            low_count[i] = 0;
            up_count[i] = 0;
        }
        for(int i=0;i<len;i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                low_count[s[i]-'a']++;
            else
                up_count[s[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(low_count[i]%2){
                ans += low_count[i]-1;
                mid = 1;
            }
            else
                ans += low_count[i];
        }
        for(int i=0;i<26;i++){
            if(up_count[i]%2){
                ans += up_count[i]-1;
                mid = 1;
            }
            else
                ans += up_count[i];
        }
        ans += mid;
        return ans;c++
    }
};
```

