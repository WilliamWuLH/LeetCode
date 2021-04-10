## Longest Increasing Path in a Matrix

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
```

**Example 3:**

```
Input: matrix = [[1]]
Output: 1
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- `0 <= matrix[i][j] <= 2^31 - 1`

#### 记忆化深度优先搜索：

​		将矩阵看成一个有向图，每个单元格对应图中的一个节点，如果相邻的两个单元格的值不相等，则在相邻的两个单元格之间存在一条从较小值指向较大值的有向边。问题转化成在有向图中寻找最长路径。

​		深度优先搜索是非常直观的方法。从一个单元格开始进行深度优先搜索，即可找到从该单元格开始的最长递增路径。对每个单元格分别进行深度优先搜索之后，即可得到矩阵中的最长递增路径的长度。

​		但是如果使用朴素深度优先搜索，时间复杂度是指数级，会超出时间限制，因此必须加以优化。

​		朴素深度优先搜索的时间复杂度过高的原因是进行了大量的重复计算，同一个单元格会被访问多次，每次访问都要重新计算。由于同一个单元格对应的最长递增路径的长度是固定不变的，因此可以使用记忆化的方法进行优化。用矩阵 memory 作为缓存矩阵，已经计算过的单元格的结果存储到缓存矩阵中。

​		使用记忆化深度优先搜索，当访问到一个单元格 ( i , j ) 时，如果 memory\[i]\[j] != 0 ，说明该单元格的结果已经计算过，则直接从缓存中读取结果，如果 memory\[i]\[j] == 0，说明该单元格的结果尚未被计算过，则进行搜索，并将计算得到的结果存入缓存中。

​		遍历完矩阵中的所有单元格之后，即可得到矩阵中的最长递增路径的长度。

为什么可以直接加上结点搜索过的值？不会有路径重叠吗？不会造成路径重复计算吗？

​		答：不会，因为我们找的是严格递增路径，所以结点和结点之间的路径是有向边，并且一个点能到另一个点，一定是这个点小于这另一个点，另一个点的 memory 记录的是它的最长递增路径的长度，路径上的每个结点都是比它大的结点，所以绝对不会出现比它小的结点，所以不会有路径的重叠。

参考：[力扣官方题解](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-le-2/)

```c++
class Solution {
public:
    static constexpr int dict[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int row=0, col=0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() <= 0 || matrix[0].size() <= 0)
            return 0;
        row = matrix.size();
        col = matrix[0].size();
        auto memory = vector<vector<int>>(row, vector<int>(col, 0));
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans = max(ans, dfs(matrix, memory, i, j));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>> & matrix, vector<vector<int>> & memory, int r, int c){
        if(memory[r][c] != 0)
            return memory[r][c];
        memory[r][c]++;
        for(int d=0; d<4; d++){
            int newr = r+dict[d][0], newc = c+dict[d][1];
            if(newr>=0 && newr<row && newc>=0 && newc<col && matrix[newr][newc] > matrix[r][c])
                memory[r][c] = max(memory[r][c], dfs(matrix, memory, newr, newc) + 1);
        }
        return memory[r][c];
    }
};
```

