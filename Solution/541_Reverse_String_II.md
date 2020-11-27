## Reverse String II

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

**Example:**

```
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```

**Restrictions:**

1. The string consists of lower English letters only.
2. Length of the given string and k will in the range [1, 10000]

#### 反转字符串：

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        int len = s.length();
        while(pos < s.length()){
            if(pos+k > s.length())
                reverse(s.begin()+pos, s.end());
            else
                reverse(s.begin()+pos, s.begin()+pos+k);
            pos += 2*k;
        }
        return s;
    }
};
```

