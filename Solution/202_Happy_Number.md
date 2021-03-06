## Happy Number

Write an algorithm to determine if a number `n` is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1. Those numbers for which this process **ends in 1** are happy numbers.

Return True if `n` is a happy number, and False if not.

**Example:** 

```
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

#### 快慢指针：

​		判断是否是快乐数的过程其实就是判断计算过程中是否有出现重复数字的过程。

​		我们要做的，就是判断计算的过程中出现的数字是否有重复，这是不是很像链表中是否存在环的判断。

​		当我们在判断链表是否存在环时，所用的方法正是快慢指针。

​		所以这道题可以使用快慢指针解决。

```c++
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = fun(n);
        while(fast != 1 && slow != fast){
            slow = fun(slow);
            fast = fun(fun(fast));
        }
        return fast == 1;
    }
    int fun(int n){
        int ans = 0;
        while(n > 0){
            ans += pow(n % 10, 2);
            n /= 10;
        }
        return ans;
    }
};
```

