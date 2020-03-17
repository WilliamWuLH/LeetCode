## Palindrome Number

####  without converting the integer to a string ：

​		负数：返回 false

​		非负数：（注意边界判断）

​				直接把整数反转，如果相等就是Palindrome Number，返回true，如果不相等就返回false。

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int rev = 0;
        int temp = x;
        while(x){
            if(rev > INT_MAX/10)
                return false;
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        if(rev == temp)
            return true;
        else
            return false;
    }
};
```

