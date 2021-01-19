## Min Cost to Connect All Points

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

The cost of connecting two points `[xi, yi]` and `[xj, yj]` is the **manhattan distance** between them: `|xi - xj| + |yi - yj|`, where `|val|` denotes the absolute value of `val`.

Return *the minimum cost to make all points connected.* All points are connected if there is **exactly one** simple path between any two points.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/08/26/d.png)

```
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
```

**Example 2:**

```
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
```

**Example 3:**

```
Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4
```

**Example 4:**

```
Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000
```

**Example 5:**

```
Input: points = [[0,0]]
Output: 0
```

**Constraints:**

- `1 <= points.length <= 1000`
- `-10^6 <= xi, yi <= 10^6`
- All pairs `(xi, yi)` are distinct.

#### 并查集 + Kruskal 算法：

​		给定一个 points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。需要返回将所有点连接的最小总费用。只有任意两点之间有且仅有一条简单路径时，才认为所有点都已连接。

​		这很明显是一个**最小生成树**的问题：[最小生成树](https://zh.wikipedia.org/wiki/%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91)

​		关于最小生成树，有两种解法比较容易且主流：[Prim算法](https://zh.wikipedia.org/wiki/%E6%99%AE%E6%9E%97%E5%A7%86%E7%AE%97%E6%B3%95) 和 [Kruskal算法](https://zh.wikipedia.org/wiki/%E5%85%8B%E9%B2%81%E6%96%AF%E5%85%8B%E5%B0%94%E6%BC%94%E7%AE%97%E6%B3%95)

​		在本题中，我们采用 Kruskal 算法，因为本题的边需要我们自己构建，所以我们可以构建边之后再进行排序，然后就可以直接采用 Kruskal 算法进行求解了。

​		在使用 Kruskal 算法时，我们连接两个点，这两个点就属于同一个连通分量了，所以我们很自然会想到使用并查集来实现。

​		具体代码如下，非常直观明了：

```c++
class DSU{
    private:
        vector<int> f, rank;
    public:
        DSU(int n){
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
        bool one_set(){
            int n = f.size();
            for(int i=1; i<n; i++)
                if(f[i-1] != f[i])
                    return false;
            return true;
        }
};
class Solution {
public:
    struct the_edge{
        int dis, start, end;
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<the_edge> edge;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                the_edge e;
                e.dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                e.start = i;
                e.end = j;
                edge.emplace_back(e);
            }
        }
        sort(edge.begin(), edge.end(), [&](const the_edge &a, const the_edge &b){
            return a.dis < b.dis;
        });
        int ans = 0;
        for(auto &i : edge){
            if(dsu.find(i.start) == dsu.find(i.end))
                continue;
            ans += i.dis;
            dsu.unionset(i.start, i.end);
            if(dsu.one_set())
                return ans;
        }
        return ans;
    }
};
```

