## Concatenation of Consecutive Binary Numbers

Given an integer `n`, return *the **decimal value** of the binary string formed by concatenating the binary representations of* `1` *to* `n` *in order, **modulo*** `10^9 + 7`.

**Example 1:**

```
Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
```

**Example 2:**

```
Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
```

**Example 3:**

```
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
```

**Constraints:**

- `1 <= n <= 10^5`

#### 模拟 + 位运算：

​		本题的难点在于溢出问题，要在乘法，加法的每一步都先进行除余运算，以保证运算过程中不会溢出。

下面是除余定理：

模的四则运算：

- (a + b) % p = (a % p + b % p) % p

- (a - b) % p = (a % p - b % p ) % p

- (a * b) % p = (a % p * b % p) % p

- a ^ b % p = ((a % p)^b) % p

结合律：

- ((a+b) % p + c) % p = (a + (b+c) % p) % p

- ((ab) % p * c)% p = (a * (bc) % p) % p

交换律：

- (a + b) % p = (b+a) % p

- (a * b) % p = (b * a) % p

分配律：

- (a+b) % p = ( a % p + b % p ) % p

- ((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p

接下来的难点就是计算每个数的二进制的长度：

代码实现一：

```c++
class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        long long ans = 0;
        for(int i=1; i<=n; i++){
            int len = 0, cur = i;
            while(cur){
                len++;
                cur >>= 1;
            }
            ans = ((ans << len) + i) % mod;
        }
        return ans % mod;
    }
};
```

代码实现二：

​		由于 2 的整数次幂的二进制表示形如 (1) 2 或者 (10⋯0) 2 的形式，将其减去 1 是形如 (0) 2 或者 (01⋯1) 2 的形式，恰好就是将减去 1 之前的二进制表示翻转之后的结果，因此如果 i & (i−1) = 0，即 i 和 i − 1 的二进制表示中没有某一位均为 1，那么 i 就是 2 的整数次幂。

**参考：[zerotrac 🌸](https://leetcode-cn.com/u/zerotrac2/)**

```c++
class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        int len = 0;
        long long ans = 0;
        for(int i=1; i<=n; i++){
            if(!(i & (i-1)))
                len++;
            ans = ((ans << len) + i) % mod;
        }
        return ans % mod;
    }
};
```

