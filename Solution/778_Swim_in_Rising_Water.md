## Swim in Rising Water

On an N x N `grid`, each square `grid[i][j]` represents the elevation at that point `(i,j)`.

Now rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square `(0, 0)`. What is the least time until you can reach the bottom right square `(N-1, N-1)`?

**Example 1:**

```
Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
```

**Example 2:**

```
Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

**Note:**

1. `2 <= N <= 50`.
2. grid[i][j] is a permutation of [0, ..., N*N - 1].

#### 并查集 + 排序：

我们把坐标方格中每一个方格抽象成一个个节点，把相邻的方格之间抽象成有一条线连接两个节点。

本题的最终目标是从坐标方格的左上平台 (0，0) 出发，到达坐标方格的右下平台 (N-1, N-1)，其实就是使得这两个节点在同一个连通分量中，所以我们可以使用并查集进行求解。

在每一个坐标方格上都有一个平台高度，我们按照方格的平台高度对方格进行排序，然后按平台高度从小到大进行遍历讨论：判断该方格相邻的各个方格的平台高度，如果该方格比相邻的方格平台高度更高，说明可以到达这个方格，它们属于同一个连通分量，如果该方格比相邻的方格平台高度更低，则不能到达。

每讨论完一个方格，可以判断一次此时 (0，0) 和 (N-1, N-1) 是否属于一个连通分量，如果属于则返回当前的平台高度，如果不属于则继续讨论。

```c++
class DSU{
    private:
        vector<int> f;
    public:
        DSU(int n){
            f.resize(n, 1);
            for(int i=0; i<n; i++)
                f[i] = i;
        }
        int find(int x){
            return x == f[x] ? f[x] : f[x] = find(f[x]);
        }
        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            f[x] = y;
            return;
        }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        vector<tuple<int, int, int>> elevation;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                elevation.emplace_back(tuple<int, int, int>(i, j, grid[i][j]));
        sort(elevation.begin(), elevation.end(), [&](const auto &a, const auto &b){
            return get<2>(a) < get<2>(b);
        });
        for(auto &e : elevation){
            auto && [i, j, val] = e;
            int pos = i * n + j;
            if(i > 0 && grid[i][j] > grid[i-1][j])
                dsu.unionset(pos, pos-n);
            if(i < n-1 && grid[i][j] > grid[i+1][j])
                dsu.unionset(pos, pos+n);
            if(j > 0 && grid[i][j] > grid[i][j-1])
                dsu.unionset(pos, pos-1);
            if(j < n-1 && grid[i][j] > grid[i][j+1])
                dsu.unionset(pos, pos+1);
            if(dsu.find(0) == dsu.find(n*n-1))
                return val;
        }
        return get<2>(elevation.back());
    }
};
```

