## Determine if Two Strings Are Close

Two strings are considered **close** if you can attain one from the other using the following operations:

- Operation 1: Swap any two existing characters.
  - For example, `abcde -> aecdb`
- Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
  - For example, `aacabb -> bbcbaa` (all `a`'s turn into `b`'s, and all `b`'s turn into `a`'s)

You can use the operations on either string as many times as necessary.

Given two strings, `word1` and `word2`, return `true` *if* `word1` *and* `word2` *are **close**, and* `false` *otherwise.*

**Example 1:**

```
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
```

**Example 2:**

```
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
```

**Example 3:**

```
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
```

**Example 4:**

```
Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
```

**Constraints:**

- `1 <= word1.length, word2.length <= 10^5`
- `word1` and `word2` contain only lowercase English letters.

#### 统计字符种类 + 统计字符出现次数：

​		题目提供了两种操作：交换任意字符的位置，转换两个字符。

​		其实仔细观察这两个操作之后的字符串和两个操作的具体含义，其实我们只需要判断字符串之间的两个条件就可以知道字符串之间能不能通过这两个操作进行接近。

这两个条件就是：

1. 两个字符串中字符的种类相同。
2. 字符串中各个字符的出现次数组成的数组在进行排序之后相同，即字符的出现次数是对应的。

具体实现：

​		先判断两个字符串是不是长度相同，接着统计字符的出现次数，并且可以判断两个字符串中字符种类是否相同，接着将统计个数的数组进行排序，再判断字符的出现次数是否对应。

```c++
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        int c1[26], c2[26];
        memset(c1, 0, sizeof(int)*26);
        memset(c2, 0, sizeof(int)*26);
        for(auto &i : word1)
            c1[i-'a']++;
        for(auto &i : word2)
            c2[i-'a']++;
        for(int i=0; i<26; i++)
            if((c1[i] == 0) ^ (c2[i] == 0))
                return false;
        sort(c1, c1+26);
        sort(c2, c2+26);
        for(int i=0; i<26; i++)
            if(c1[i] != c2[i])
                return false;
        return true;
    }
};
```

