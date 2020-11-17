## Matrix Cells in Distance Order

#### 距离顺序排列矩阵单元格：

​		首先把全部矩阵的单元格都存入答案数组中，然后再根据距离进行排序即可。

```c++
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                ans.push_back(vector<int>{i, j});
            }
        }
        sort(ans.begin(), ans.end(), [&](const vector<int> &a, const vector<int> &b){
            int al = abs(a[0]-r0) + abs(a[1]-c0);
            int bl = abs(b[0]-r0) + abs(b[1]-c0);
            if(al < bl)
                return true;
            return false;
        });
        return ans;
    }
};
```

