## Minimum Operations to Reduce X to Zero

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return *the **minimum number** of operations to reduce* `x` *to **exactly*** `0` *if it's possible**, otherwise, return* `-1`.

**Example 1:**

```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

**Example 2:**

```
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```

**Example 3:**

```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `1 <= x <= 10^9`

#### 逆向思维 + 滑动窗口（找最长窗口）：

​		给一个整数数组 nums 和一个整数 x 。每一次操作时，移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要修改数组以供接下来的操作使用。

​		如果可以将 x 恰好减到 0 ，返回最小操作数，否则，返回 -1 。

​		让我们进行逆向思维来思考这道题，设整数数组中所有元素的和为 sum，那么我们要使数组左右的元素相加等于 x，就相当于找到数组中间元素的和为 sum - x，同时，要使得左右元素的个数最小，也就是求数组中间元素的个数最大。

​		明确了要求什么之后，我们可以使用滑动窗口的方法来找到最长的窗口，这个窗口满足元素总和为 sum - x。具体实现请详见代码，大概思路为先确定窗口的右边界，使得窗口中元素之和满足 >= sum - x，然后再滑动窗口的左边界，使得窗口中的元素 < sum - x 之后，重新回到确定窗口的右边界。在这期间，如果窗口的元素之和满足等于 sum - x，应该更新答案，最后找到最长的窗口。

​		通过最长的滑动窗口，可以确定最小的左右边操作数。

```c++
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        for(auto &i : nums)
            sum += i;
        sum = sum - x;
        int ans = -1, cur = 0, l = 0, r = 0;
        while(r < n){
            cur += nums[r++];
            while(cur > sum && l < r)
                cur -= nums[l++];
            if(cur == sum)
                ans = max(ans, r - l);
        }
        return ans == -1 ? -1 : n - ans;
    }
};
```

