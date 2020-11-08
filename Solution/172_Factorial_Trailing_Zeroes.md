## Factorial Trailing Zeroes

#### 方法一：直接阶乘再算尾数

​		最简单，但是复杂度太高。

#### 方法二：计算有几个因子 5

​		计算阶乘之后末尾有几个 0，其实就是算阶乘期间和几个 10 相乘，也就是和几对 2 * 5 相乘。

​		由于是阶乘，所以乘过的因子 2 的个数绝对是比因子 5 的个数多的，所以只需要计算 5 的个数。

1. 先算有几个数是 5 的倍数，即 1-n 有几个数可以被 5 整除。
2. 由于 25 = 5 * 5，所以如果有 25 的倍数，还可以提取出一个 5，所以再加上 1-n 有几个数可以被 25 整除。
3. 由于 125 = 5 * 5 * 5，算完 25 的倍数之后，125 还可以再提取一个 5，再加上可以被 125 整除的个数。
4. 以此类推……

##### 编程实现 1：

```c++
class Solution {
public:
    int trailingZeroes(int n) {
        int k = 5;
        int ans = 0;
        while(k <= n){
            ans += n/k;
            k *= 5;
        }
        return ans;
    }
};
```

##### 编程实现 2：

```c++
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n >= 5){
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
```

##### 编程实现 3：

```c++
class Solution {
public:
    int trailingZeroes(int n) {
        return n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625+n/1953125+n/9765625+n/48828125;
    }
};
```

