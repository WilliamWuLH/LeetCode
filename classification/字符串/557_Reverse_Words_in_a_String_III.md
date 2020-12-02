## Reverse Words in a String III

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**

```
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

**Note:** In the string, each word is separated by single space and there will not be any extra space in the string.

#### 判断空格 + 反转字符串：

```c++
class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        while(start != s.length()){
            while(s[end] != ' ' && end != s.length())
                end++;
            reverse(s.begin()+start, s.begin()+end);
            while(s[end] == ' ' && end != s.length())
                end++;
            start = end;
        }
        return s;
    }
};
```

