## Valid Anagram

Given two strings *s* and *t* , write a function to determine if *t* is an anagram of *s*.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

**Note:**
You may assume the string contains only lowercase alphabets.

**Follow up:**
What if the inputs contain unicode characters? How would you adapt your solution to such case?

#### 排序：

​		判断是不是有效的字母异位词，只要把“异位”变成“同位”就好了，所以排序简单的解决了这个问题。

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

#### 哈希：

​		判断是不是有效的字母异位词，直接统计字符串所含字母的个数。

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26];
        memset(hash, 0, sizeof(int)*26);
        for(auto i : s)
            hash[i-'a']++;
        for(auto i : t)
            hash[i-'a']--;
        for(auto i : hash){
            if(i != 0)
                return false;
        }
        return true;
    }
};
```

