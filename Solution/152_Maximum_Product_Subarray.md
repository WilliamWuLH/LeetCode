## Maximum Product Subarray

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.

**Example 1:**

```
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**

```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

#### 动态规划：

​		由于是乘法运算，所以最大的数可能是通过负数乘以负数，也可能是正数乘以正数。

​		所以在讨论到数组中的某一个数时需要维护一个以该数结尾的子数组的最大值和最小值（可能为负数）。

​		讨论到每一个数时需要时刻更新此时的答案（最大值）。

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tmax = 1,tmin = 1;
        int ans = INT_MIN;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(nums[i] < 0)
                swap(tmax, tmin);
            tmax = max(tmax * nums[i], nums[i]);
            tmin = min(tmin * nums[i], nums[i]);
            ans = max(ans, tmax);
        }
        return ans;
    }
};
```

