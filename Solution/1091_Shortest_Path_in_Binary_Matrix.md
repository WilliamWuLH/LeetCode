## Shortest Path in Binary Matrix

In an N by N square grid, each cell is either empty (0) or blocked (1).

A *clear path from top-left to bottom-right* has length `k` if and only if it is composed of cells `C_1, C_2, ..., C_k` such that:

- Adjacent cells `C_i` and `C_{i+1}` are connected 8-directionally (ie., they are different and share an edge or corner)
- `C_1` is at location `(0, 0)` (ie. has value `grid[0][0]`)
- `C_k` is at location `(N-1, N-1)` (ie. has value `grid[N-1][N-1]`)
- If `C_i` is located at `(r, c)`, then `grid[r][c]` is empty (ie. `grid[r][c] == 0`).

Return the length of the shortest such clear path from top-left to bottom-right. If such a path does not exist, return -1.

**Example 1:**

```
Input: [[0,1],[1,0]]

Output: 2
```

**Example 2:**

```
Input: [[0,0,0],[1,1,0],[1,1,0]]

Output: 4
```

**Note:**

1. `1 <= grid.length == grid[0].length <= 100`
2. `grid[r][c]` is `0` or `1`

#### 广度优先搜索 BFS：

​		返回从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。

​		很明显可以使用广度优先搜索的方法，使用广度优先搜索的优点在于我们找到的第一条从左上角到右下角的路径就是我们最终要求的最短畅通路径。

​		首先可以判断起始点是不是阻塞，如果起始点是阻塞的则不需要后续判断，直接返回 -1。

​		接下来可以通过一个二维数组规定路径遍历的八个方向，方便后续广度优先搜索的代码实现。

​		使用一个队列实现广度优先搜索，初始化为起始点 ( 0 , 0 )，每次从队列中取出一个节点并且判断该节点是不是终点，如果是则返回当前的路径长度，因为使用的是广度优先搜索，找到的第一条畅通路径就是我们要求的最短畅通路径（因为路径的权重相同）。如果该节点还不是终点，说明我们需要继续进行广度优先搜索，把该节点可以遍历到的下一个节点添加到队列中，并且更新此时新添加的节点的路径长度，并且把该节点设置为已经访问过。

​		最后，当广度优先搜索结束时，即队列为空时，如果还没有找到可以到达终点的畅通路径，返回 -1。

```c++
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        int n = grid.size();
        int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<tuple<int, int, int>> bfs;
        bfs.push(tuple<int, int, int>(0, 0, 1));
        grid[0][0] = 1;
        while(!bfs.empty()){
            auto [v1, v2, v3] = bfs.front();
            if(v1 + v2 == 2 * n - 2)
                return v3;
            bfs.pop();
            for(int i=0; i<8; i++){
                int r = v1+d[i][0], c = v2+d[i][1];
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0){
                    bfs.push(tuple<int, int, int>(r, c, v3+1));
                    grid[r][c] = 1;
                }
            }
        }
        return -1;
    }
};
```

