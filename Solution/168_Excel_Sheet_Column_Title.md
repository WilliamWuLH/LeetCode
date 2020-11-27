## Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
```

**Example 1:**

```
Input: 1
Output: "A"
```

**Example 2:**

```
Input: 28
Output: "AB"
```

**Example 3:**

```
Input: 701
Output: "ZY"
```

#### “26进制”：

​		其实就是相当于26进制，从 A 开始，到 Z 结束，再加一就要进位。

重点难点：这个 n-- 非常灵性，由于 A 是从 1 开始，所以需要通过减一来实现从 A-Z 到 0-25 的映射，才可以通过模26（%26）来确定所属的字母。

```c++
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n){
            n--;
            ans = (char)('A'+(n % 26)) + ans;
            n /= 26;
        }
        return ans;
    }
};
```

