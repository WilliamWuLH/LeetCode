## Unique Paths II

#### 回溯法——runtime error 超时：

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans = 0;
        if(obstacleGrid[0][0] == 1)
            return 0;
        dfs(obstacleGrid, ans, 0, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& obstacleGrid, int &ans, int x, int y){
        if(x == obstacleGrid.size()-1 && y == obstacleGrid[0].size()-1 && obstacleGrid[x][y] == 0){
            ans++;
            return;
        }
        if(x+1 < obstacleGrid.size() && obstacleGrid[x+1][y] == 0)
            dfs(obstacleGrid, ans, x+1, y);
        if(y+1 < obstacleGrid[0].size() && obstacleGrid[x][y+1] == 0)
            dfs(obstacleGrid, ans, x, y+1);
        return;
    }
};
```

#### 动态规划：

​		碰到障碍物就跳过，所以障碍物所在处路径为 0。

​		边缘只有一条路可以走，所以边缘路径为 1。

​		其他地方的路径等于从上方到达的路径数目加上从左边到达的路径数目。

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ylen = obstacleGrid.size();
        int xlen = obstacleGrid[0].size();
        vector<vector<int>> count(ylen, vector<int>(xlen, 0));
        if(obstacleGrid[0][0])
            return 0;
        for(int i=0; i<ylen; i++){
            for(int j=0; j<xlen; j++){
                if(obstacleGrid[i][j])
                    continue;
                if(i == 0 && j == 0)
                    count[i][j] = 1;
                else if(i == 0)
                    count[i][j] = count[i][j-1];
                else if(j == 0)
                    count[i][j] = count[i-1][j]; 
                else
                    count[i][j] = count[i-1][j] + count[i][j-1];
            }
        }
        return count[ylen-1][xlen-1];
    }
};
```

