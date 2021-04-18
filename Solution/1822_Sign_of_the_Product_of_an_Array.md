## Sign of the Product of an Array

## 5726. 数组元素积的符号

There is a function `signFunc(x)` that returns:

- `1` if `x` is positive.
- `-1` if `x` is negative.
- `0` if `x` is equal to `0`.

You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.

Return `signFunc(product)`.

**Example 1:**

```
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```

**Example 2:**

```
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
```

**Example 3:**

```
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-100 <= nums[i] <= 100`

#### 统计数组中负数的个数：

​		如果数组中有 0，直接返回 0。

​		如果没有 0，统计数组中负数的个数，负数有偶数个返回 1，有奇数个返回 -1。

```c++
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        for(auto &i : nums)
            if(i == 0)
                return 0;
            else if(i < 0)
                cnt++;
        return cnt % 2 == 0 ? 1 : -1;
    }
};
```

