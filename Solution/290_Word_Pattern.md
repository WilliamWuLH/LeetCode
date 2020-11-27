## Word Pattern

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.

**Example 1:**

```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

**Example 2:**

```
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

**Example 3:**

```
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

**Example 4:**

```
Input: pattern = "abba", s = "dog dog dog dog"
Output: false
```

**Constraints:**

- `1 <= pattern.length <= 300`
- `pattern` contains only lower-case English letters.
- `1 <= s.length <= 3000`
- `s` contains only lower-case English letters and spaces `' '`.
- `s` **does not contain** any leading or trailing spaces.
- All the words in `s` are separated by a **single space**.

#### 字符串单词提取 + 哈希匹配：

```c++
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> the_s;
        map<char, string> hash1;
        map<string, char> hash2;
        split_s(s, the_s);
        if(pattern.size() != the_s.size())
            return false;
        for(int i=0; i<pattern.size(); i++){
            if(hash1.count(pattern[i]) && hash1[pattern[i]] != the_s[i])
                return false;
            if(hash2.count(the_s[i]) && hash2[the_s[i]] != pattern[i])
                return false;
            hash1[pattern[i]] = the_s[i];
            hash2[the_s[i]] = pattern[i];
        }
        return true;
    }
    void split_s(string s, vector<string> &the_s){
        string temp = "";
        for(auto i : s){
            if(i == ' '){
                if(temp.size())
                    the_s.push_back(temp);
                temp = "";
            }
            else
                temp += i;
        }
        if(temp.size())
            the_s.push_back(temp);
        return;
    }
};
```

