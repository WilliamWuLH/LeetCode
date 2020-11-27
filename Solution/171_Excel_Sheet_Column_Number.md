## Excel Sheet Column Number

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
```

**Example 1:**

```
Input: "A"
Output: 1
```

**Example 2:**

```
Input: "AB"
Output: 28
```

**Example 3:**

```
Input: "ZY"
Output: 701
```

**Constraints:**

- `1 <= s.length <= 7`
- `s` consists only of uppercase English letters.
- `s` is between "A" and "FXSHRXW".

#### “26进制”：

​		和 168 题类似。

​		A 到 Z，26个字母，由于 A-Z 对应的是 1-26，所以需要加一。

```c++
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans *= 26;
            ans += s[i] - 'A' + 1;
        }
        return ans;
    }
};
```

