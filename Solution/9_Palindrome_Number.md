## Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

**Follow up:** Could you solve it without converting the integer to a string?

**Example 1:**

```
Input: x = 121
Output: true
```

**Example 2:**

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Example 4:**

```
Input: x = -101
Output: false
```

**Constraints:**

- `-2^31 <= x <= 2^31 - 1`

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

