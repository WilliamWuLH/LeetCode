## Isomorphic Strings

Given two strings **s** and **t**, determine if they are isomorphic.

Two strings are isomorphic if the characters in **s** can be replaced to get **t**.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

**Example 1:**

```
Input: s = "egg", t = "add"
Output: true
```

**Example 2:**

```
Input: s = "foo", t = "bar"
Output: false
```

**Example 3:**

```
Input: s = "paper", t = "title"
Output: true
```

**Note:**
You may assume both **s** and **t** have the same length.

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

