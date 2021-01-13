## Redundant Connection

In this problem, a tree is an **undirected** graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of `edges`. Each element of `edges` is a pair `[u, v]` with `u < v`, that represents an **undirected** edge connecting nodes `u` and `v`.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge `[u, v]` should be in the same format, with `u < v`.

**Example 1:**

```
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
```

**Example 2:**

```
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
```

**Note:**

The size of the input 2D-array will be between 3 and 1000.

Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

#### 并查集：

​		输入一个图，该图由一个有着 N 个节点 (节点值不重复 1, 2, ..., N ) 的树及一条附加的边构成。附加的边的两个顶点包含在 1 到 N 中间，这条附加的边不属于树中已存在的边。

​		结果图是一个以边组成的二维数组。每一个边的元素是一对 \[ u, v \] ，满足 u < v，表示连接顶点 u 和 v 的无向图的边。

​		返回一条可以删去的边，使得结果图是一个有着 N 个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 \[ u, v \] 应满足相同的格式 u < v。

​		很典型的并查集，遍历所给的边集，通过边把各个节点连接到一个连通分量中，如果某一条边的两个节点已经在同一个连通分量里面了，则这条边就是冗余边，也就是答案。

```c++
class DSU{
    private:
        int n;
        vector<int> f;
        vector<int> rank;
    public:
        DSU(int N){
            n = N;
            f.resize(n, 1);
            rank.resize(n ,1);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);
        for(auto &i : edges){
            if(dsu.find(i[0]) == dsu.find(i[1]))
                return i;
            dsu.unionset(i[0], i[1]);
        }
        return edges.back();
    }
};
```

