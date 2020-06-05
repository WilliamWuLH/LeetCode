## Reverse String II

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

