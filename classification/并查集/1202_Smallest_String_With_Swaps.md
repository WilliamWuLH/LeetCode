## Smallest String With Swaps

You are given a string `s`, and an array of pairs of indices in the string `pairs` where `pairs[i] = [a, b]` indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given `pairs` **any number of times**.

Return the lexicographically smallest string that `s` can be changed to after using the swaps.

**Example 1:**

```
Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
```

**Example 2:**

```
Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
```

**Example 3:**

```
Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `0 <= pairs.length <= 10^5`
- `0 <= pairs[i][0], pairs[i][1] < s.length`
- `s` only contains lower case English letters.

#### 并查集：

​		既然可以任意地交换通过「索引对」直接相连的字符，那么我们也任意地交换通过「索引对」间接相连的字符。我们利用这个性质将该字符串抽象：将每一个字符抽象为「点」，那么这些「索引对」即为「边」，我们只需要维护这个「图」的连通性即可。对于同属一个连通块（极大连通子图）内的字符，我们可以任意地交换它们。

​		这样我们的思路就很清晰了：利用并查集维护任意两点的连通性，将同属一个连通块内的点提取出来，直接排序后放置回其在字符串中的原位置即可。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

**并查集：[OI Wiki 并查集](https://oi-wiki.org/ds/dsu/)**

```c++
class DisjointSetUnion
{
    bool path_compression = true;

    private:
        int n;
        vector<int> f;
        vector<int> rank;
    
    public:
        DisjointSetUnion(int N){
            n = N;
            rank.resize(n, 1);
            f.resize(n, 1);
            for(int i=0; i<n; i++)
                f[i] = i;
        }

        int find(int x){
            if(path_compression){
                if(x != f[x])
                    f[x] = find(f[x]);
                return f[x];
            }
            else{
                if(x == f[x])
                    return x;
                return find(f[x]);
            }
        }

        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            f[x] = y;
        }

        void unionset_by_rank(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            if(rank[x] > rank[y])
                swap(x, y);
            f[x] = y;
            rank[y] += rank[x];
        }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int plen = pairs.size();
        int slen = s.length();
        unordered_map<int, vector<int>> hash;
        if(plen == 0)
            return s;
        DisjointSetUnion dsu(slen);
        for(auto &i : pairs)
            dsu.unionset_by_rank(i[0], i[1]);
        for(int i=0; i<slen; i++)
            hash[dsu.find(i)].emplace_back(s[i]);
        for(auto &[key, value] : hash)
            sort(value.begin(), value.end(), greater<int>());
        for(int i=0; i<slen; i++){
            int temp = dsu.find(i);
            s[i] = hash[temp].back();
            hash[temp].pop_back();
        }
        return s;
    }
};
```

