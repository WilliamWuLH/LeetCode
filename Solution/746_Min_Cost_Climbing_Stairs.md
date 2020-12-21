## Min Cost Climbing Stairs

On a staircase, the `i`-th step has some non-negative cost `cost[i]` assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

**Example 1:**

```
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
```

**Example 2:**

```
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
```

**Note:**

1. `cost` will have a length in the range `[2, 1000]`.
2. Every `cost[i]` will be an integer in the range `[0, 999]`.

#### 动态规划：

​		每一层阶梯只能通过之前的两层阶梯到达，所以子问题就是当前阶梯是从之前的两层阶梯中的哪一层阶梯到达可以使得花费的体力值最小，也就是为了最小的总体力花费值，应该从哪一层阶梯到达当前阶梯。

​		而最优子结构就是当每一层阶梯都是之前花费最小的体力值到达的，那么最终的总体力值也是这种情况下需要花费的最小体力值。

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; i++)
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        return dp[n];
    }
};
```

#### 动态规划 + 优化：

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int stair1 = 0, stair2 = 0, cur_stair = 0;
        for(int i=2; i<=n; i++){
            cur_stair = min(stair1 + cost[i-2], stair2 + cost[i-1]);
            stair1 = stair2;
            stair2 = cur_stair;
        }
        return cur_stair;
    }
};
```

