## Broken Calculator

On a broken calculator that has a number showing on its display, we can perform two operations:

- **Double**: Multiply the number on the display by 2, or;
- **Decrement**: Subtract 1 from the number on the display.

Initially, the calculator is displaying the number `X`.

Return the minimum number of operations needed to display the number `Y`.

**Example 1:**

```
Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
```

**Example 2:**

```
Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
```

**Example 3:**

```
Input: X = 3, Y = 10
Output: 3
Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
```

**Example 4:**

```
Input: X = 1024, Y = 1
Output: 1023
Explanation: Use decrement operations 1023 times.
```

**Note:**

1. `1 <= X <= 10^9`
2. `1 <= Y <= 10^9`

#### 逆向思维：

**思路**

​		除了对 X 执行乘 2 或减 1 操作之外，我们也可以对 Y 执行除 2（当 Y 是偶数时）或者加 1 操作。这样做的动机是我们可以总是贪心地执行除 2 操作：

- 当 Y 是偶数，如果先执行 2 次加法操作，再执行 1 次除法操作，我们可以通过先执行 1 次除法操作，再执行 1 次加法操作以使用更少的操作次数得到相同的结果：( Y + 2 ) / 2 vs Y / 2 + 1。

- 当 Y 是奇数，如果先执行 3 次加法操作，再执行 1 次除法操作，我们可以将其替代为顺次执行加法、除法、加法操作以使用更少的操作次数得到相同的结果：( Y + 3 ) / 2 vs ( Y + 1 ) / 2 + 1。

**算法**

​		当 Y 大于 X 时，如果它是奇数，我们执行加法操作，否则执行除法操作。之后，我们需要执行 X - Y 次加法操作以得到 X。

**为什么这道题采用逆向思维更优？**

正向思维：在 X < Y 时要实现操作数最小，要将 X 逼近 Y 的 1 / 2 值或 1 / 4 值或 1 / 8 值或 ... 再进行 \* 2 操作，难点在于要判断要逼近的是 1 / 2 值还是 1 / 4 值还是其他值，逻辑复杂

逆向思维：在 Y > X 时 Y 只管 / 2，到了 Y < X 时在 +1 逼近。

说白了就是，正向思维采用的是先小跨度的 -1 操作，再大跨度的 \* 2 操作；逆向思维采用的是先大跨度的 / 2 操作，再小跨度的 -1 操作。然而事实上往往是先大后小的解决问题思维在实现起来会比较简单 

参考：[力扣 (LeetCode)](https://leetcode-cn.com/problems/broken-calculator/solution/pi-liao-de-ji-suan-qi-by-leetcode/)

```c++
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(Y > X){
            ans++;
            if(Y % 2)
                Y++;
            else
                Y >>= 1;
        }
        return ans + X - Y;
    }
};
```

