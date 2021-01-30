## Similar String Groups

Two strings `X` and `Y` are similar if we can swap two letters (in different positions) of `X`, so that it equals `Y`. Also two strings `X` and `Y` are similar if they are equal.

For example, `"tars"` and `"rats"` are similar (swapping at positions `0` and `2`), and `"rats"` and `"arts"` are similar, but `"star"` is not similar to `"tars"`, `"rats"`, or `"arts"`.

Together, these form two connected groups by similarity: `{"tars", "rats", "arts"}` and `{"star"}`. Notice that `"tars"` and `"arts"` are in the same group even though they are not similar. Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list `strs` of strings where every string in `strs` is an anagram of every other string in `strs`. How many groups are there?

**Example 1:**

```
Input: strs = ["tars","rats","arts","star"]
Output: 2
```

**Example 2:**

```
Input: strs = ["omv","ovm"]
Output: 1
```

**Constraints:**

- `1 <= strs.length <= 100`
- `1 <= strs[i].length <= 1000`
- `sum(strs[i].length) <= 2 * 10^4`
- `strs[i]` consists of lowercase letters only.
- All words in `strs` have the same length and are anagrams of each other.

#### PS：2021年第一个月就要结束了，这个月真的写了好多并查集的题目，收获颇丰！

#### 并查集 + 判断字符串是否相似：

**题目大意：**

​		如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。

​		总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。

​		给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。求 strs 中有多少个相似字符串组？

**思路：**

​		我们要将相似的字符串归为一组，只要有一个字符串和另一个字符串是相似的，那么这两个字符串就是属于同一个相似字符串组。这种关系类似于两个节点之间有一条边相连，那么它们就属于同一个连通分量。我们很自然的想到可以使用并查集来维护这种连通分量的关系，也就是是否属于同一个相似字符串组的关系。

​		确定好如何维护给定的字符串组中的字符串是否属于同一个相似字符串组之后，我们的问题就是如何判断两个字符串是否相似。根据题目所给的 “相似性” 的要求，我们首先判断两个字符串长度是否相等，再判断两个字符串是否相等，最后再判断两个字符串是不是只有两个位置不同，并且字符串中不同的位置的字符是相对应的。

​		最后，返回并查集中集合的数目，也就是相似字符串组的数目。

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
        int countset(){
            int count = 0;
            int n = f.size();
            for(int i=0; i<n; i++)
                if(i == find(i))
                    count++;
            return count;
        }
};
class Solution {
public:
    bool similar(const string &a, const string &b){
        int n = a.length();
        if(n != b.length())
            return false;
        if(a == b)
            return true;
        int p1 = -1, p2 = -1;
        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                if(p1 == -1)
                    p1 = i;
                else if(p2 == -1)
                    p2 = i;
                else
                    return false;
            }
        }
        if(p2 == -1)
            return false;
        return a[p1] == b[p2] && a[p2] == b[p1];
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU dsu(n);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(similar(strs[i], strs[j]))
                    dsu.unionset(i, j);
            }
        }
        return dsu.countset();
    }
};
```

