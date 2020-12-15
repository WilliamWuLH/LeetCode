## Monotone Increasing Digits

Given a non-negative integer `N`, find the largest number that is less than or equal to `N` with monotone increasing digits.

(Recall that an integer has *monotone increasing digits* if and only if each pair of adjacent digits `x` and `y` satisfy `x <= y`.)

**Example 1:**

```
Input: N = 10
Output: 9
```

**Example 2:**

```
Input: N = 1234
Output: 1234
```

**Example 3:**

```
Input: N = 332
Output: 299
```

**Note:** `N` is an integer in the range `[0, 10^9]`.

#### 贪心：

记 strN[i] 表示数字 N 从高到低的第 i 位的数字（ i 从 0 开始）。

如果整个数字 N 本身已经是按位单调递增的，那么最大的数字即为 N。

如果找到第一个位置 i 使得 \[ 0 , i-1 \] 的数位单调递增且 strN[i−1] > strN[i]，此时 \[ 0 , i \] 的数位都与 N 的对应数位相等，仍然被 N 限制着，即我们不能随意填写 \[ i+1 , n-1\] 位置上的数字。为了得到最大的数字，我们需要解除 N 的限制，来让剩余的低位全部变成 9，即能得到小于 N 的最大整数。而从贪心的角度考虑，我们需要尽量让高位与 N 的对应数位相等，故尝试让 strN\[i−1\] 自身数位减 1。此时已经不再受 N 的限制，直接将 \[ i , n-1 \] 的位置上的数全部变为 9 即可。

但这里存在一个问题：当 strN\[i−1\] 自身数位减 1 后可能会使得 strN\[i−1\] 和 strN\[i−2\] 不再满足递增的关系，因此我们需要从 i−1 开始递减比较相邻数位的关系，直到找到第一个位置 j 使得 strN[j] 自身数位减 1 后 strN\[j−1\] 和 strN[j] 仍然保持递增关系，或者位置 j 已经到最左边（即 j 的值为 0），此时我们将 \[ j+1 , n-1\] 的数全部变为 9 才能得到最终正确的答案。

参考：

[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)

```c++
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1, len = strN.length();
        while(i < len && strN[i-1] <= strN[i])
            i++;
        if(i < len){
            while(i > 0 && strN[i-1] > strN[i]){
                strN[i-1]--;
                i--;
            }
            for(i += 1; i < len; i++)
                strN[i] = '9';
        }
        return stoi(strN);
    }
};
```

