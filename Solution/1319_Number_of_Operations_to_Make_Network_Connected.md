## Number of Operations to Make Network Connected

There are `n` computers numbered from `0` to `n-1` connected by ethernet cables `connections` forming a network where `connections[i] = [a, b]` represents a connection between computers `a` and `b`. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the *minimum number of times* you need to do this in order to make all the computers connected. If it's not possible, return -1. 

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png)**

```
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png)**

```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
```

**Example 3:**

```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
```

**Example 4:**

```
Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
```

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= connections.length <= min(n*(n-1)/2, 10^5)`
- `connections[i].length == 2`
- `0 <= connections[i][0], connections[i][1] < n`
- `connections[i][0] != connections[i][1]`
- There are no repeated connections.
- No two computers are connected by more than one cable.

#### 并查集：

​		用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。给定这个计算机网络的初始布线 connections，可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1 。 

​		其实本题我们要求的就是两个值：**通过初始布线 connections 连接形成的连通分量的数量**，**每个连通分量中多余的连接线数量**。

​		在每个连通分量中，多余的连接线可以拨开，并且拿去连接两个不同的连通分量，使得两个不同的连通分量连接成同一个连通分量。所以我们还需要知道通过初始布线 connections 连接形成的连通分量的数量，判断多余的连接线够不够把所有的连通分量连接在一起。

​		使用并查集完成初始布线 connections 的连通分量连接。注意：我们稍微修改了合并 unionset 的返回值，当两个节点已经属于同一个集合（连通分量）时返回 1，如果需要执行合并操作则返回 0，这么做的原因是为了方便我们找到连通分量中多余的连接线。

​		通过如上讨论，求得连通分量数量和多余连接线的数量十分简单，具体代码如下：

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
        int countset(){
            int count = 0, n = f.size();
            for(int i=0; i<n; i++)
                if(f[i] == i)
                    count++;
            return count;
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int line = 0;
        DSU dsu(n);
        for(auto &i : connections){
            int cur = dsu.unionset(i[0], i[1]);
            if(cur)
                line++;
        }
        return dsu.countset() - 1 <= line ? dsu.countset() - 1 : -1;
    }
};
```

