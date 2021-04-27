## Power of Three

Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.

**Example 1:**

```
Input: n = 27
Output: true
```

**Example 2:**

```
Input: n = 0
Output: false
```

**Example 3:**

```
Input: n = 9
Output: true
```

**Example 4:**

```
Input: n = 45
Output: false
```

**Constraints:**

- `-2^31 <= n <= 2^31 - 1`

#### 方法一：

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n >= 3){
            if(n % 3)
                return false;
            n /= 3;
        }
        return n == 1;
    }
};
```

#### 方法二：

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
```

