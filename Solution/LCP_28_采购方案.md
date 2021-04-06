## LCP 28. 采购方案

小力将 N 个零件的报价存于数组 nums。小力预算为 target，假定小力仅购买两个零件，要求购买零件的花费不超过预算，请问他有多少种采购方案。

注意：答案需要以 1e9 + 7 (1000000007) 为底取模，如：计算初始结果为：1000000008，请返回 1

- 示例 1：

> 输入：nums = [2,5,3,5], target = 6

> 输出：1

> 解释：预算内仅能购买 nums[0] 与 nums[2]。

- 示例 2：

> 输入：nums = [2,2,1,9], target = 10

> 输出：4

> 解释：符合预算的采购方案如下：
> nums[0] + nums[1] = 4
> nums[0] + nums[2] = 3
> nums[1] + nums[2] = 3
> nums[2] + nums[3] = 10

- 提示：

> 2 <= nums.length <= 10^5
> 1 <= nums[i], target <= 10^5

#### 排序 + 缩减遍历范围（运用双指针）：

​		首先排序，方便我们后续可以缩减需要遍历的范围。

​		本题的大概意思就是在一个数组中找两个元素相加，相加的和不大于某个特定值，就算一种合法情况，要找出有多少种这种合法情况。

​		我们首先排序，然后运用双指针的思想，一个指针 i 指向当前数组中要讨论的最小元素 nums[i] ，另一个指针 up 指向要讨论的最大元素 nums[up]。

​		如果此时要讨论的最小元素 nums[i] 和最大元素 nums[up] 相加仍然大于特定值 target，那么下一个最小元素 nums[i+1] 大于 nums[i]，必然不可能和 nums[up] 相加可以满足不大于特定值 target，所以 nums[up] 这个元素可以不再进行遍历，直接 up--。

​		当最小元素 nums[i] 和最大元素 nums[up] 相加不大于特定值 target 时，可以组成的配对个数为 up - i。

​		后面的情况以此类推，直到 up <= i 可以退出。

```c++
class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        const int mod = 1000000007;
        sort(nums.begin(), nums.end());
        long long ans = 0, n = nums.size(), up = n-1;
        for(int i=0; i<n; i++){
            while(up >= 0 && nums[i] + nums[up] > target)
                up--;
            if(up <= i)
                break;
            ans = (ans + up - i) % mod;
        }
        return ans % mod;
    }
};
```

