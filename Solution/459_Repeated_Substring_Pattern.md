## Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

**Example 1:**

```
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
```

**Example 2:**

```
Input: "aba"
Output: False
```

**Example 3:**

```
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
```

#### 将字符串分割为等长的子字符串 + 判断子字符串是否相等：

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len < 2)
            return false;
        for(int i=2; i<=len; i++){
            if(len % i)
                continue;
            int slen = len / i;
            int pos = 0;
            string first = s.substr(pos, slen);
            while(1){
                pos += slen;
                if(pos == len)
                    break;
                string temp = s.substr(pos, slen);
                if(temp != first)
                    break;
            }
            if(pos == len)
                return true;
        }
        return false;
    }
};
```

