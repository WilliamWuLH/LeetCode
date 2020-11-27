## Find Words That Can Be Formed by Characters

You are given an array of strings `words` and a string `chars`.

A string is *good* if it can be formed by characters from `chars` (each character can only be used once).

Return the sum of lengths of all good strings in `words`.

**Example 1:**

```
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
```

**Example 2:**

```
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
```

**Note:**

1. `1 <= words.length <= 1000`
2. `1 <= words[i].length, chars.length <= 100`
3. All strings contain lowercase English letters only.

#### 建字母表统计字母出现个数：

```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count[26];
        int ans = 0;
        for(int i=0;i<26;i++)
            count[i] = 0;
        for(int i=0;i<chars.length();i++){
            count[chars[i]-'a']++;
        }
        vector<string>::iterator iter;
        for(iter=words.begin();iter!=words.end();iter++){
            string s = *iter;
            int i;
            int temp[26];
            for(i=0;i<26;i++)
                temp[i] = count[i];
            for(i=0;i<s.length();i++){
                temp[s[i]-'a']--;
                if(temp[s[i]-'a'] < 0)
                    break;
            }
            if(i < s.length())
                continue;
            else
                ans += s.length();
        }
        return ans;
    }
};
```

