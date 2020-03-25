## Surface Area of 3D Shapes

#### 空间想象 + 先加后减：

​			讨论每一个坐标：

- 如果该坐标的值等于 0，说明在该坐标没有正方块，所以没有表面积，不需要计算。
- 如果该坐标的值大于 0，说明有正方块，需要计算表面积：
  - 先加：该坐标的表面积包含上下两个 1 * 1 的面，以及四个 1 * grid[ i ] [ j ] 的面，先加到答案中。
  - 后减：减去被其他正方块遮掉的面，为了避免重复计算，统一减去该坐标的前方和左方的遮盖的面：
    - 前方：如果前方存在坐标，遮掉的面积为：min ( grid [i-1] [j], grid [i] [j] ) * 2
    - 左方：如果左方存在坐标，遮掉的面积为：min ( grid [i] [j-1], grid [i] [j] ) * 2

```c++
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int len = grid.size();
        int ans = 0;
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(grid[i][j] > 0){
                    ans += grid[i][j] * 4 + 2;
                    if(i > 0)
                        ans -= min(grid[i-1][j], grid[i][j]) * 2;
                    if(j > 0)
                        ans -= min(grid[i][j-1], grid[i][j]) * 2;
                }
            }
        }
        return ans;
    }
};
```

