## Fibonacci Number

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
```

Given `N`, calculate `F(N)`.

**Example 1:**

```
Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

**Example 2:**

```
Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

**Example 3:**

```
Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

**Note:**

0 ≤ `N` ≤ 30.

#### 递归：

```c++
class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        else if(N == 1)
            return 1;
        else
            return fib(N-1) + fib(N-2);
    }
};
```

#### 2021.1.4 再回首

#### 动态规划：

```c++
class Solution {
public:
    int fib(int N) {
        int f0 = 0, f1 = 1, f2;
        for(int i=2; i<=N; i++){
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return N < 2 ? N : f2;
    }
};
```

#### 通项公式：

```c++
class Solution {
public:
    int fib(int N) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, N) - pow((1 - sqrt5) / 2, N);
        return round(fibN / sqrt5);
    }
};
```

