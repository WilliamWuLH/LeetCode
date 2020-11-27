## Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

**Example 1:**

```
Input: [5,7]
Output: 4
```

**Example 2:**

```
Input: [0,1]
Output: 0
```

#### 把最右边的 1 变为 0：

**代码一：**

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int zero = 0;
        while(n > m){
            zero ++;
            m >>= 1;
            n >>= 1;
        }
        return n << zero;
    }
};
```

**代码二：**

​		从 n 开始计算，判断 n 是否大于 m：

​		如果此时 n 小于等于 m，说明此时的 n 的最右边的 “1” 以及这个 “1” 的左边所有位都是从 m 到最开始的 n 之间所有数都一样的，所以与运算之后是不会改变的，而 n 的最右边的 “1” 的右边的位会因为某个数的这个位出现了 0 而使得最终的答案存在 0。

​		如果此时 n 大于 m，则当前 n 的最右边的 “1” 将会被比它小的数相与而变成 “0”，所以此时令 n 和 n-1 做与运算，为什么是 n-1 ？，因为此时最坏的情况就是 n-1 = m，不会导致超出范围而发生错误。

​		最后 n 小于等于 m 跳出循环，得到答案 n。

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while( n > m){
            n = n & (n-1);
        }
        return n;
    }
};
```

