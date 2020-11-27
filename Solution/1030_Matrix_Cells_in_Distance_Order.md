## Matrix Cells in Distance Order

We are given a matrix with `R` rows and `C` columns has cells with integer coordinates `(r, c)`, where `0 <= r < R` and `0 <= c < C`.

Additionally, we are given a cell in that matrix with coordinates `(r0, c0)`.

Return the coordinates of all cells in the matrix, sorted by their distance from `(r0, c0)` from smallest distance to largest distance. Here, the distance between two cells `(r1, c1)` and `(r2, c2)` is the Manhattan distance, `|r1 - r2| + |c1 - c2|`. (You may return the answer in any order that satisfies this condition.)

**Example 1:**

```
Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]
```

**Example 2:**

```
Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
```

**Example 3:**

```
Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
```

**Note:**

1. `1 <= R <= 100`
2. `1 <= C <= 100`
3. `0 <= r0 < R`
4. `0 <= c0 < C`

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

