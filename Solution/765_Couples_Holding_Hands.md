## Couples Holding Hands

N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A *swap* consists of choosing **any** two people, then they stand up and switch seats.

The people and seats are represented by an integer from `0` to `2N-1`, the couples are numbered in order, the first couple being `(0, 1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2N-2, 2N-1)`.

The couples' initial seating is given by `row[i]` being the value of the person who is initially sitting in the i-th seat.

**Example 1:**

```
Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
```

**Example 2:**

```
Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
```

**Note:**

1. `len(row)` is even and in the range of `[4, 60]`.
2. `row` is guaranteed to be a permutation of `0...len(row)-1`.

#### 并查集：

​		假定第一对情侣的男生与第二对情侣的女生坐在了一起，而第二对情侣的男生与第三对情侣的女生坐在了一起。根据题意，要想让第二对情侣之间能够成功牵手，要么交换第一对情侣的男生与第二对情侣的男生，要么交换第二对情侣的女生与第三对情侣的女生。

​		既然存在这两种交换方式，那么有必要两种方式都考虑吗？答案是无需都考虑。不难注意到，无论采用了两种交换方式中的哪一种，最后的结局都是「第二对情侣坐在了一起，且第一对情侣的男生与第三对情侣的女生坐在了一起」，因此两种交换方式是等价的。

​		因此，我们将 N 对情侣看做图中的 N 个节点；对于每对相邻的位置，如果是第 i 对与第 j 对坐在了一起，则在 i 号节点与 j 号节点之间连接一条边，代表需要交换这两对情侣的位置。

​		如果图中形成了一个大小为 k 的环：i → j → k → … → l → i，则我们沿着环的方向，先交换 i , j 的位置，再交换 j , k 的位置，以此类推。在进行了 k − 1 次交换后，这 k 对情侣就都能够彼此牵手了。

​		故我们只需要利用并查集求出图中的每个连通分量；对于每个连通分量而言，其大小减 1 就是需要交换的次数。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

```c++
class DSU{
    private:
        int n;
        vector<int> f;
    public:
        DSU(int N){
            n = N;
            f.resize(n, 0);
            for(int i=0; i<n; i++)
                f[i] = i;
        }
        int find(int x){
            return f[x] == x ? f[x] : f[x] = find(f[x]);
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU dsu(n / 2);
        int ans = 0;
        for(int i=0; i<n; i+=2)
            dsu.unionset(row[i]/2, row[i+1]/2);
        unordered_map<int, int> count;
        for(int i=0; i<n/2; i++)
            count[dsu.find(i)]++;
        for(const auto & [set, size] : count)
            ans += size - 1;
        return ans;
    }
};
```

