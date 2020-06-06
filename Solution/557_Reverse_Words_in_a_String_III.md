## Reverse Words in a String III

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

