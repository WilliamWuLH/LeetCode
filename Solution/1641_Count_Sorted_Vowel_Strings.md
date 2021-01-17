## Count Sorted Vowel Strings

Given an integer `n`, return *the number of strings of length* `n` *that consist only of vowels (*`a`*,* `e`*,* `i`*,* `o`*,* `u`*) and are **lexicographically sorted**.*

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
```

**Example 2:**

```
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
```

**Example 3:**

```
Input: n = 33
Output: 66045
```

**Constraints:**

- `1 <= n <= 50` 

#### 将 n 个小球放到 5 个盒子里，盒子可以为空：

​		数学解法，可以把问题转换成：将 n 个小球放到 5 个盒子里，盒子可以为空。

​		想象把 n 个字符分配给五个元音所代表的盒子中。一旦每个盒子中的字符个数定了，那么这个字符串也固定下来了。因为题目要求必须是字典序，所以一定 a 字符在最前；其次是 e 字符；其次是 i 字符；其次是 o 字符；其次是 u 字符。

​		下面问题的关键就是，n 个小球放到 5 个盒子里，盒子可以为空，一共有多少种方法？

这是经典的中学数学问题。更一般的，我们来探讨，将 n 个小球放到 m 个盒子里，有多少种方法？

​		首先，我们考虑问题的简单版本，即盒子不能为空的情况。

​		此时只需要把 n 个小球排成一排，中间放 m - 1 个隔板，放好以后，相当于把 n 个小球分成了 m 份。每一份对应一个盒子里的小球数量。因为盒子不能为空，所以两个小球之间不可能放多个隔板，左右两端也不可能放隔板。因此，放隔板的位置有 n - 1 个，我们要放 m - 1 个隔板。答案为 C(n - 1, m - 1)。

​		有了这个结论，再来讨论问题的复杂版本，就简单了，即盒子可以为空的情况。

​		此时只需要先拿 m 个新的小球，在 m 个盒子里，每个盒子中扔进去一个小球。之后，再分配原来的这 n 个小球，得到的分配结果，肯定 m 个盒子里都不为空。但此时，我们使用了 n + m 个小球。

​		换句话说，把 n 个小球放到 m 个盒子里，盒子可以为空，等价于：把 n + m 个小球放到 m 个盒子里，盒子不能为空。

​		可以想成是：我们先把 n + m 个小球放到 m 个盒子里，盒子不能为空，然后再在每个盒子里拿走 1 个小球，总共拿走了 m 个小球，得到的结果，就是把 n 个小球放到 m 个盒子里，盒子可以为空的解。

​		把 n + m 个小球放到 m 个盒子里，盒子不能为空的分法，带入上面的公式，就是 C(n + m - 1, m - 1)

​		所以，把 n 个小球放到 m 个盒子里，盒子可以为空，答案为 C(n + m - 1, m - 1)。

总结：

​		将 n 个小球放到 m 个盒子里，盒子不为空：C(n - 1, m - 1)；

​		将 n 个小球放到 m 个盒子里，盒子可以空：C(n + m - 1, m - 1)；

对于这个问题，m = 5，盒子可以为空，所以答案是 C(n + 5 - 1, 5 - 1) = C(n + 4, 4)

**参考：[liuyuboboboL4](https://leetcode-cn.com/u/liuyubobobo/)**

```c++
class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }
};
```

