## Minimum Path Sum

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

