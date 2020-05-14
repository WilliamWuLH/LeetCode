## Guess Number Higher or Lower

#### 二分查找：

​		使用 long 长整型防止溢出导致执行错误。

```c++
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long left = 1, right = (long)n+1;
        long ans = (right - left)/2 + left;
        while(guess(ans) != 0){
            if(guess(ans) == -1)
                right = ans;
            else
                left = ans+1;
            ans = (right - left)/2 + left;
        }
        return (int)ans;
    }
};
```

