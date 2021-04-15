## House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.

**Example 1:**

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

**Example 2:**

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 3:**

```
Input: nums = [0]
Output: 0
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`

#### 动态规划：

由题意可知：第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

所以我的动态规划分为两个部分：

- 一定有闯入第一个房屋的：那么不计算最后一个房屋，并且从第三个房屋开始计算（因为第二个房屋一定不能闯入，否则就闯入相邻的房屋了）。
- 一定没有闯入第一个房屋的：计算最后一个房屋，并且从第二个房屋开始计算。

动态规划的状态转移方程：

- 当前房屋不闯入：max(上一个房屋不闯入的金额，上一个房屋闯入的金额)
- 当前房屋闯入：上一个房屋不闯入的金额 + 这个房屋闯入的金额

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int have[2][2] = {{nums[0], nums[0]}, {nums[0], nums[0]}};
        int nohave[2][2] = {{0, 0}, {0, 0}};
        for(int i=1; i<n; i++){
            if(i > 1 && i < n-1){
                have[1][0] = max(have[0][0], have[0][1]);
                have[1][1] = have[0][0]+nums[i];
                have[0][0] = have[1][0];
                have[0][1] = have[1][1];
            }
            nohave[1][0] = max(nohave[0][0], nohave[0][1]);
            nohave[1][1] = nohave[0][0]+nums[i];
            nohave[0][0] = nohave[1][0];
            nohave[0][1] = nohave[1][1];
        }
        return max(max(have[1][0], have[1][1]), max(nohave[1][0], nohave[1][1]));
    }
};
```

