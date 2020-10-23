## Excel Sheet Column Number

#### “26进制”：

​		和 168 题类似。

​		A 到 Z，26个字母，由于 A-Z 对应的是 1-26，所以需要加一。

```c++
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans *= 26;
            ans += s[i] - 'A' + 1;
        }
        return ans;
    }
};
```

