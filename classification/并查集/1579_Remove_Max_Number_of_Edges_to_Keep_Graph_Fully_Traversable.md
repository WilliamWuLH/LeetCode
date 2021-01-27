## Remove Max Number of Edges to Keep Graph Fully Traversable

Alice and Bob have an undirected graph of `n` nodes and 3 types of edges:

- Type 1: Can be traversed by Alice only.
- Type 2: Can be traversed by Bob only.
- Type 3: Can by traversed by both Alice and Bob.

Given an array `edges` where `edges[i] = [typei, ui, vi]` represents a bidirectional edge of type `typei` between nodes `ui` and `vi`, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return *the maximum number of edges you can remove, or return* `-1` *if it's impossible for the graph to be fully traversed by Alice and Bob.*

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/08/19/ex1.png)**

```
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/08/19/ex2.png)**

```
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
```

**Example 3:**

**![img](https://assets.leetcode.com/uploads/2020/08/19/ex3.png)**

```
Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
```

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)`
- `edges[i].length == 3`
- `1 <= edges[i][0] <= 3`
- `1 <= edges[i][1] < edges[i][2] <= n`
- All tuples `(typei, ui, vi)` are distinct.

#### 并查集 + 按照优先级添加边：

​		本题中，最开始无向图中只有节点，没有边。然后题目给我们一个边的集合，其中有的边是只有 Alice 能走（类型 1），有的边是只有 Bob 能走（类型 2），有的边是 Alice 和 Bob 都可以走的（类型 3）。我们要做的就是把边添加到无向图中，然后在保证 Alice 和 Bob 都可以遍历无向图的情况下，删除最多的边。换一个思路，其实就是在边的集合中，找出最少数量的边，使得 Alice 和 Bob 都可以遍历这个无向图。

​		通过上述的分析，我们可以知道类型 3 的边最为重要，因为类型 3 的边 Alice 和 Bob 都可以走，一个顶俩，有时需要两条边完成的工作它一条边就完成了，所以类型 3 的边优先级最高，应该最先讨论被添加入无向图。

​		在添加完类型 3 的边之后，对于 Alice 来说，就剩下类型 1 的边可以用了，而对于 Bob 来说，也只剩下类型 2 的边可以使用，所以接下来各自添加类型 1 的边到 Alice 的无向图中，添加类型 2 的边到 Bob 的无向图中。

在进行每个类型的边的添加的过程中，我们可以同时进行边的删除工作：

​		我们采用并查集来完成无向图中连通分量的维护，我们希望添加的边可以连接两个不同的连通分量，所以当有一条边连接的两个节点属于同一个连通分量时，说明这条边可以被删除。

​		最后需要判断 Alice 和 Bob 根据现有边是不是都可以遍历无向图，如果不行则返回 -1，如果行返回可以删除的边的数目。

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
        int unionset(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return 1;
            if(rank[x] > rank[y])
                swap(x, y);
            f[x] = y;
            rank[y] += rank[x];
            return 0;
        }
        bool oneset(){
            int theset = find(0);
            for(auto &i : f)
                if(find(i) != theset)
                    return false;
            return true;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int ans = 0;
        for(auto &i : edges){
            if(i[0] == 3){
                int a = alice.unionset(i[1]-1, i[2]-1);
                int b = bob.unionset(i[1]-1, i[2]-1);
                if(a + b == 2)
                    ans++;
            }
        }
        for(auto &i : edges){
            if(i[0] == 1)
                if(alice.unionset(i[1]-1, i[2]-1))
                    ans++;
            if(i[0] == 2)
                if(bob.unionset(i[1]-1, i[2]-1))
                    ans++;
        }
        return alice.oneset() && bob.oneset() ? ans : -1;
    }
};
```

