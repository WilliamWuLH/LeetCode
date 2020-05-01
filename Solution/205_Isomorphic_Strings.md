## Isomorphic Strings

#### 两个字符串互相建立字符映射：

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen != tlen)
            return false;
        map<char, char> shash;
        map<char, char> thash;
        for(int i=0; i<slen; i++){
            if(shash.count(s[i])){
                if(shash[ s[i] ] != t[i])
                    return false;
            }
            shash[ s[i] ] = t[i];
            if(thash.count(t[i])){
                if(thash[ t[i] ] != s[i])
                    return false;
            }
            thash[ t[i] ] = s[i];
        }
        return true;
    }
};
```

