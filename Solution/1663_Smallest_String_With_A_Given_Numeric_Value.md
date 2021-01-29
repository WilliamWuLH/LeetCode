## Smallest String With A Given Numeric Value

The **numeric value** of a **lowercase character** is defined as its position `(1-indexed)` in the alphabet, so the numeric value of `a` is `1`, the numeric value of `b` is `2`, the numeric value of `c` is `3`, and so on.

The **numeric value** of a **string** consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string `"abe"` is equal to `1 + 2 + 5 = 8`.

You are given two integers `n` and `k`. Return *the **lexicographically smallest string** with **length** equal to `n` and **numeric value** equal to `k`.*

Note that a string `x` is lexicographically smaller than string `y` if `x` comes before `y` in dictionary order, that is, either `x` is a prefix of `y`, or if `i` is the first position such that `x[i] != y[i]`, then `x[i]` comes before `y[i]` in alphabetic order.

**Example 1:**

```
Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
```

**Example 2:**

```
Input: n = 5, k = 73
Output: "aaszz"
```

**Constraints:**

- `1 <= n <= 10^5`
- `n <= k <= 26 * n`

#### 数学计算：

​		这道题的本质就是数学计算。

​		仔细读题之后可以发现，我们可以把答案分为三个部分：开头的 'a' 部分，中间其他字母的部分，最后的 ’z‘ 部分。

​		我们首先把答案初始化为长度为 n 的全部是 'a' 的字符串。接着，我们计算最后的 'z' 部分的长度，由于此时我们已经初始化字符串为全部是 'a' 的字符串，所以可以使用公式 ( k - n ) / 25 来获取尾部有多少个 'z'。然后我们就要计算中间的其他字母的部分，通过公式 ( k - n ) % 25 可以计算中间的其他字母是哪一个字母。

​		最后构建我们最终的答案，将字符串的尾部换成刚刚计算出来的 'z' 的长度，然后再替换我们刚刚计算出来的中间字母，最后就得到了我们的答案字符串。

```c++
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int tail = (k-n)/25;
        int middle = (k-n)%25;
        for(int i=1; i<=tail; i++)
            ans[n-i] = 'z';
        if(middle)
            ans[n-1-tail] = (char)('a'+middle);
        return ans;
    }
};
```

