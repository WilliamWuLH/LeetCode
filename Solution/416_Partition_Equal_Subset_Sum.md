## Partition Equal Subset Sum

Given a **non-empty** array `nums` containing **only positive integers**, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

**Example 1:**

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

**Example 2:**

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

**Constraints:**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

#### 动态规划（类似于 0-1 背包问题）：

​		遍历数组中的每个数字，对于每个数字遍历所有的容量，判断在该容量下数字可不可以放入，放入后能不能满足要求。

​		唯一需要注意的是 j 应该从后往前反向遍历，因为每个物品（或者说数字）只能用一次，以免之前的结果影响其他的结果。

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;
        if(sum % 2)
            return false;
        sum = sum / 2;
        bool dp[sum+1];
        memset(dp, false, (sum+1)*sizeof(bool));
        dp[0] = true;
        for(int i=0; i<len; i++){
            for(int j=sum; j>=0; j--){
                if(j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
```

