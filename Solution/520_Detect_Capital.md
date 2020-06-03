## Detect Capital

#### 分类讨论：

```c++
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0] >= 'a' && word[0] <= 'z'){
            for(int i=1; i<word.length(); i++)
                if(word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            return true;
        }
        else if(word[0] >= 'A' && word[0] <= 'Z'){
            int count = 0;
            for(int i=1; i<word.length(); i++)
                if(word[i] >= 'a' && word[i] <= 'z')
                    count++;
            if(count == word.length()-1 || count == 0)
                return true;
            else
                return false;
        }
        return false;
    }
};
```

