## Climbing Stairs

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

**Constraints:**

- `1 <= n <= 45`

#### 动态规划：

​		记录保存爬到每一层楼梯的路径数目，当层数大于等于 2 时，该层的路径数目等于前一层的路径数目加上前两层的路径数目。

```c++
class Solution {
public:
    int climbStairs(int n) {
        int path[n+1];
        path[0] = 1;
        path[1] = 1;
        for(int i=2; i<=n; i++){
            path[i] = path[i-1] + path[i-2];
        }
        return path[n];
    }
};
```

