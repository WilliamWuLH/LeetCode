## Minimum Operations to Make Array Equal

You have an array `arr` of length `n` where `arr[i] = (2 * i) + 1` for all valid values of `i` (i.e. `0 <= i < n`).

In one operation, you can select two indices `x` and `y` where `0 <= x, y < n` and subtract `1` from `arr[x]` and add `1` to `arr[y]` (i.e. perform `arr[x] -=1 `and `arr[y] += 1`). The goal is to make all the elements of the array **equal**. It is **guaranteed** that all the elements of the array can be made equal using some operations.

Given an integer `n`, the length of the array. Return *the minimum number of operations* needed to make all the elements of arr equal.

**Example 1:**

```
Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
```

**Example 2:**

```
Input: n = 6
Output: 9
```

**Constraints:**

- `1 <= n <= 10^4`

#### 数学技巧：

​		通过题目已知数组的组织方法为：arr\[i] = (2 * i) + 1，由此可知长度为 n 的数组有如下特性：

- 数组的第一个元素是 1，最后一个元素为 $(2 * (n - 1) + 1) = 2n - 1$。
- 数组的期望（均值）一定是 n，通过 $\frac{(1 + (2n - 1)) * n}{2 * n} = n$ 计算可知。
- 数组中相邻的两个元素的数值相差为 2。

通过以上的特性，我们可以把数组分成两个部分，一部分是比 n （均值）小的元素，一部分是比 n （均值）大的元素。由于我们要通过操作使得数组全部元素相等，并且一次操作是使一个元素加一的同时一个元素减一，所以最快的方法就是使得数组元素逼近均值。

通过以上分析可知，要是数组元素逼近均值，我们仅需要计算比 n 小的部分（或者比 n 大的部分）全部操作为和均值相等需要多少次操作就可以了。因为一次操作可以使得一个元素变大的同时另一个元素变小，即两边同时逼近均值。

又因为数组中相邻的两个元素的数值相差为 2，所以在同一个需要被操作的元素部分中（比 n 小的部分或者比 n 大的部分），相邻元素操作成均值的次数相差为 2，所以可以从最小的 1 开始计算操作为均值需要多少次，然后讨论下一个元素时仅需要把操作数减 2，以此类推，直到操作数小于等于 0 结束。

累计以上的操作数就是最后的答案了。

```c++
class Solution {
public:
    int minOperations(int n) {
        int k = n-1, ans = 0;
        while(k > 0){
            ans += k;
            k -= 2;
        }
        return ans;
    }
};
```

