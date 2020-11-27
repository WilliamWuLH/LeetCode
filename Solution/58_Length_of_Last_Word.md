## Length of Last Word

Given a string `s` consists of some words separated by spaces, return *the length of the last word in the string. If the last word does not exist, return* `0`.

A **word** is a maximal substring consisting of non-space characters only.

**Example 1:**

```
Input: s = "Hello World"
Output: 5
```

**Example 2:**

```
Input: s = " "
Output: 0
```

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of only English letters and spaces `' '`.

#### 从后往前，记录头尾：

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length() - 1;
        while(index >= 0 && s[index] == ' ')
            index--;
        if(index < 0)
            return 0;
        int end = index;
        while(index >= 0 && s[index] != ' ')
            index--;
        return end - index;
    }
};
```

