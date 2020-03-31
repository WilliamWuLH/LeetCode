## Number of Islands

#### 深度优先搜索 DFS：

```c++
class Solution {
public:
    int dic[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int v_len = grid.size();
        if(v_len == 0)
            return 0;
        int h_len = grid[0].size();
        for(int i=0; i<v_len; i++){
            for(int j=0; j<h_len; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = 'v';
                    int pos[2] = {i, j};
                    dfs(pos, grid);
                }
            }
        }
        return ans;
    }
    void dfs(int pos[], vector<vector<char>>& grid){
        for(int i=0; i<4; i++){
            int now[2] = {pos[0]+dic[i][0], pos[1]+dic[i][1]};
            if(now[0] >= 0 && now[0] < grid.size() && 
                now[1] >= 0 && now[1] < grid[0].size()){
                if(grid[ now[0] ][ now[1] ] == '1'){
                    grid[ now[0] ][ now[1] ] = 'v';
                    dfs(now, grid);
                }
            }
        }
        return;
    }
};
```

