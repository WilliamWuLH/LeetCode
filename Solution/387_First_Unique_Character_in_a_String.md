## First Unique Character in a String

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

**Examples:**

```
s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
```

**Note:** You may assume the string contains only lowercase English letters.

#### 方法一：两次遍历：count + find

​		第一次遍历：count，对字符串中的每个字符进行计数，统计字符串中各个字符的出现个数。

​		第二次遍历：find，通过上一次遍历得到的字符串各个字符的统计个数可以找出第一个不重复的字符。

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26];
        int n = s.length();
        memset(count, 0, sizeof(int)*26);
        for(auto &i : s)
            count[i-'a']++;
        for(int i=0; i<n; i++)
            if(count[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};
```

#### 方法二：两次遍历：index + find

​		第一次遍历：index，存下字符串中每个字符的索引，如果字符还未出现，则索引为 -1，如果字符重复出现，则索引为 -2，如果字符当前只出现一次，则索引为字符在字符串中的位置。

​		第二次遍历：find，遍历索引表 index，找出索引最小的值，如果索引都是 -2，说明没有不重复的字符。

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        int index[26];
        int n = s.length();
        memset(index, -1, sizeof(int)*26);
        for(int i=0; i<n; i++){
            int pos = s[i] - 'a';
            if(index[pos] == -1)
                index[pos] = i;
            else if(index[pos] > -1)
                index[pos] = -2;
        }
        int ans = -1;
        for(int i=0; i<26; i++){
            if(index[i] > -1)
                ans = ans == -1 ? index[i] : min(ans, index[i]);
        }
        return ans;
    }
};
```

