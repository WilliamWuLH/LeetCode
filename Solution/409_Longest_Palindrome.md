## Longest Palindrome 

Given a string `s` which consists of lowercase or uppercase letters, return *the length of the **longest palindrome*** that can be built with those letters.

Letters are **case sensitive**, for example, `"Aa"` is not considered a palindrome here.

**Example 1:**

```
Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
```

**Example 2:**

```
Input: s = "a"
Output: 1
```

**Example 3:**

```
Input: s = "bb"
Output: 2
```

**Constraints:**

- `1 <= s.length <= 2000`
- `s` consits of lower-case **and/or** upper-case English letters only.

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

