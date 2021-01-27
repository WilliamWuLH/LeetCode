## Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference** in heights between two consecutive cells of the route.

Return *the minimum **effort** required to travel from the top-left cell to the bottom-right cell.*

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex1.png)

```
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex2.png)

```
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2020/10/04/ex3.png)

```
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

**Constraints:**

- `rows == heights.length`
- `columns == heights[i].length`
- `1 <= rows, columns <= 100`
- `1 <= heights[i][j] <= 10^6`

#### 并查集：

首先简化题目：

- 把每个格子抽象成图中的一个节点
- 将每两个相邻的格子之间连接一条边，长度为这两个格子本身权值的差的绝对值
- 需要找到一条从左上角到右下角的「最短路径」，其中路径的长度定义为路径上所有边的权值的最大值。

使用并查集的思路很简单：

​		可以将所有边按照长度进行排序并依次添加进并查集，直到左上角和右下角连通为止。

具体实现时，可以把长度相同的边作为一个集合，然后按照长度从小到大依次添加对应的边到并查集中，每次添加完一种长度的边之后，判断此时左上角和右下角是否属于一个集合，即是否在一个连通分量中，如果是则返回当前长度，如果不是则继续添加下一个长度的边。

```c++
class DSU{
    private:
        int n;
        vector<int> f, rank;
    public:
        DSU(int N){
            n = N;
            f.resize(n, 1);
            rank.resize(n, 1);
            for(int i=0; i<n; i++)
                f[i] = i;
        }
        int find(int x){
            if(x != f[x])
                f[x] = find(f[x]);
            return f[x];
        }
        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            if(rank[x] > rank[y])
                swap(x, y);
            f[x] = y;
            rank[y] += rank[x];
            return;
        }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        map<int, vector<int>> path;
        int m = heights.size(), n = heights[0].size();
        DSU dsu(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j+1 < n){
                    int cost = abs(heights[i][j] - heights[i][j+1]);
                    path[cost].emplace_back(i*n+j);
                    path[cost].emplace_back(i*n+j+1);
                }
                if(i+1 < m){
                    int cost = abs(heights[i][j] - heights[i+1][j]);
                    path[cost].emplace_back(i*n+j);
                    path[cost].emplace_back((i+1)*n+j);
                }
            }
        }
        map<int, vector<int>>::iterator it;
        for(it=path.begin(); it != path.end(); it++){
            int l = it->second.size();
            for(int i=0; i<l; i+=2)
                dsu.unionset(it->second[i], it->second[i+1]);
            if(dsu.find(0) == dsu.find(m*n-1))
                return it->first;
        }
        return 0;
    }
};
```

