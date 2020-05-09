## Reverse String

#### 头尾元素互换：

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1)
            return;
        int pos = 0;
        while(pos < s.size()/2){
            char temp;
            temp = s[pos];
            s[pos] = s[s.size()-1-pos];
            s[s.size()-1-pos] = temp;
            pos++;
        }
        return;
    }
};
```

