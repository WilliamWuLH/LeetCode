## Divide Two Integers

Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing `dividend` by `divisor`.

The integer division should truncate toward zero, which means losing its fractional part. For example, `truncate(8.345) = 8` and `truncate(-2.7335) = -2`.

**Note:**

- Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For this problem, assume that your function **returns 2^31 − 1 when the division result overflows**.

**Example 1:**

```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
```

**Example 2:**

```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
```

**Example 3:**

```
Input: dividend = 0, divisor = 1
Output: 0
```

**Example 4:**

```
Input: dividend = 1, divisor = 1
Output: 1
```

**Constraints:**

- `-2^31 <= dividend, divisor <= 2^31 - 1`
- `divisor != 0`

#### 倍增 + 递归：

​		给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

​		返回被除数 dividend 除以除数 divisor 得到的商。

​		整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

参考：[liujin](https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/)

```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return dividend;
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return dividend > INT_MIN ? -dividend : INT_MAX;
        long a = dividend, b = divisor;
        int sign = 1;
        if( ( a > 0 && b < 0) || (a < 0 && b > 0) )
            sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long ans = div(a, b);
        return sign > 0 ? (ans > INT_MAX ? INT_MAX : ans) : -ans;
    }
    int div(long a, long b){
        if(a < b)
            return 0;
        long count = 1;
        long tb = b;
        while( ( tb + tb ) < a ){
            count = count + count;
            tb = tb + tb;
        }
        return count + div(a - tb, b);
    }
};
```

