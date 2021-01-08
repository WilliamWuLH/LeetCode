## Check If Two String Arrays are Equivalent

Given two string arrays `word1` and `word2`, return `true` *if the two arrays **represent** the same string, and* `false` *otherwise.*

A string is **represented** by an array if the array elements concatenated **in order** forms the string.

**Example 1:**

```
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
```

**Example 2:**

```
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
```

**Example 3:**

```
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
```

**Constraints:**

- `1 <= word1.length, word2.length <= 10^3`
- `1 <= word1[i].length, word2[i].length <= 10^3`
- `1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3`
- `word1[i]` and `word2[i]` consist of lowercase letters.

#### 拼接字符串数组：

​		很简单，直接把两个字符串数组各自拼接成字符串，判断两个字符串是否相等。

```c++
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(auto &i : word1)
            s1 += i;
        for(auto &i : word2)
            s2 += i;
        return s1 == s2;
    }
};
```

