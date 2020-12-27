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

### 2020.12.27 再思考：

#### 使用 unordered_map 可以优化：

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen != tlen)
            return false;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for(int i=0; i<slen; i++){
            if((s2t.count(s[i]) && s2t[s[i]] != t[i]) || (t2s.count(t[i]) && t2s[t[i]] != s[i]))
                return false;
            s2t[s[i]] = t[i];
            t2s[t[i]]  =s[i];
        }
        return true;
    }
};
```

#### 使用 char 数组终极优化：

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        char s2t[128];
        char t2s[128];
        memset(s2t, 0, sizeof(char)*128);
        memset(t2s, 0, sizeof(char)*128);
        for(int i=0; i<slen; i++){
            if((s2t[s[i]] != 0 && s2t[s[i]] != t[i]) || (t2s[t[i]] != 0 && t2s[t[i]] != s[i]))
                return false;
            s2t[s[i]] = t[i];
            t2s[t[i]]  =s[i];
        }
        return true;
    }
};
```

