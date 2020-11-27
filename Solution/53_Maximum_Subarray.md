## Maximum Subarray

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*.

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

**Example 1:**

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2:**

```
Input: nums = [1]
Output: 1
```

**Example 3:**

```
Input: nums = [0]
Output: 0
```

**Example 4:**

```
Input: nums = [-1]
Output: -1
```

**Example 5:**

```
Input: nums = [-2147483647]
Output: -2147483647
```

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`

#### 动态规划：

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        int len = nums.size();
        int ans = nums[0];
        dp.push_back(nums[0]);
        for(int i=1; i<len; i++){
            dp.push_back(nums[i]);
            if(dp[i-1] + nums[i] > dp[i])
                dp[i] = dp[i-1] + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

