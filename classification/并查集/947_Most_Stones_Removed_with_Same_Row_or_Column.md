## Most Stones Removed with Same Row or Column

On a 2D plane, we place `n` stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either **the same row or the same column** as another stone that has not been removed.

Given an array `stones` of length `n` where `stones[i] = [xi, yi]` represents the location of the `ith` stone, return *the largest possible number of stones that can be removed*.

**Example 1:**

```
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
```

**Example 2:**

```
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
```

**Example 3:**

```
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
```

**Constraints:**

- `1 <= stones.length <= 1000`
- `0 <= xi, yi <= 10^4`
- No two stones are at the same coordinate point.

#### 并查集：

​		n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。

​		如果一块石头的同行或者同列上有其他石头存在，那么就可以移除这块石头。

​		给你一个长度为 n 的数组 stones，其中 stones\[ i \] = \[ xi, yi \] 表示第 i 块石头的位置，返回可以移除的石子的最大数量。

​		没看出来吧，其实本题也属于并查集的一种。

​		随机选择一个石头作为起点，我们可以根据这个石头的行和列进行深度优先搜索，每一层的搜索都可以找到和上一层节点的行或者列相等的石头，然后我们可以反过来，从叶子节点开始删除石头，根据深度优先搜索得到的搜索树，我们最终将只剩下一个节点，也就是根节点。

​		根据可以移除石头的规则：如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。

​		可以发现：一定可以把一个连通图里的所有顶点根据这个规则删到只剩下一个顶点。

​		为什么这么说呢？既然这些顶点在一个连通图里，可以通过遍历的方式（深度优先遍历或者广度优先遍历）遍历到这个连通图的所有顶点。那么就可以按照遍历的方式 逆向 移除石头，最后只剩下一块石头。所以：最多可以移除的石头的个数 = 所有石头的个数 - 连通分量的个数。

​		所以问题转移到在整张图中有多少个连通分量上，是不是很熟悉，这就是并查集可以解决的问题。

​		由于并查集底层是一维数组，而本题所给的石头位置是一个二维坐标，但是好在求的是**同行或者同列**，所以我们可以将行和列同等对待，只要找出在行上或者列上相同的节点就可以了。

​		根据题目所给的数据范围，我们可以把行数或者列数映射到更高的**数量级**上，即把行或者列再加上 10000，得到新的行数或者列数，防止行列的数量级相等而造成冲突。

​		详细见代码！一看就懂的那种！（只要你真的理解了并查集的思想）

```c++
class DSU{
    private:
        int set_count;
        unordered_map<int, int> f;
    public:
        int find(int x){
            if(!f.count(x))
                f[x] = x;
            if(x != f[x])
                f[x] = find(f[x]);
            return f[x];
        }
        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            f[x] = y;
        }
        int get_set_count(){
            set_count = 0;
            for(auto &[a, b] : f)
                if(a == b)
                    set_count++;
            return set_count;
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        for(auto &i : stones)
            dsu.unionset(i[0], i[1]+10000);
        return stones.size() - dsu.get_set_count();
    }
};
```

