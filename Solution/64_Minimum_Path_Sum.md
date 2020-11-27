## Minimum Path Sum

Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example 1:**

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

**Example 2:**

```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `0 <= grid[i][j] <= 100`

#### 动态规划：

​			记录到达每个位置的最小路径和，最后得到到达目标位置的最小路径和。

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();            
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j != 0)
                    grid[i][j] += grid[i][j-1];
                else if(i != 0 && j == 0)
                    grid[i][j] += grid[i-1][j];
                else if(i != 0 && j != 0)
                    grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};
```

