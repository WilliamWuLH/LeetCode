## Fibonacci Number

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

