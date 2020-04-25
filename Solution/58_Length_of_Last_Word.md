## Length of Last Word

#### 从后往前，记录头尾：

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length() - 1;
        while(index >= 0 && s[index] == ' ')
            index--;
        if(index < 0)
            return 0;
        int end = index;
        while(index >= 0 && s[index] != ' ')
            index--;
        return end - index;
    }
};
```

