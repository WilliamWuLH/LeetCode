## Add to Array-Form of Integer

For a non-negative integer `X`, the *array-form of `X`* is an array of its digits in left to right order. For example, if `X = 1231`, then the array form is `[1,2,3,1]`.

Given the array-form `A` of a non-negative integer `X`, return the array-form of the integer `X+K`.

**Example 1:**

```
Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
```

**Example 2:**

```
Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
```

**Example 3:**

```
Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
```

**Example 4:**

```
Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
```

**Note：**

1. `1 <= A.length <= 10000`
2. `0 <= A[i] <= 9`
3. `0 <= K <= 10000`
4. If `A.length > 1`, then `A[0] != 0`

#### 逐位相加：

​		这种类似于数组相加的简单题，最需要注意的就是进位。

​		我们从题目所给的数组的最后一个元素（也就是数组所表示的数的最低位）开始，逐位和数字 K 的对应位进行相加，同时需要考虑低一位的进位 carry。从数组的最后一个元素（数的最低位）逐位进行相加到数组的第一个元素（数的最高位）。

​		此时还没有结束，需要判断当前 K 是否还有剩余的数没有进行计算，并且需要注意现在的进位 carry 是否为 1，一直到数 K 计算结束和 carry 没有进位才算结束。

​		详细代码如下：

```c++
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size(), carry = 0;
        for(int i=n-1; i>=0; i--){
            A[i] += K % 10 + carry;
            carry = A[i] / 10;
            A[i] %= 10;
            K /= 10;
        }
        while(K || carry){
            int sum = K % 10 + carry;
            A.insert(A.begin(), sum % 10);
            carry = sum / 10;
            K /= 10;
        }
        return A;
    }
};
```

