## Number of Equivalent Domino Pairs

Given a list of `dominoes`, `dominoes[i] = [a, b]` is *equivalent* to `dominoes[j] = [c, d]` if and only if either (`a==c` and `b==d`), or (`a==d` and `b==c`) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs `(i, j)` for which `0 <= i < j < dominoes.length`, and `dominoes[i]` is equivalent to `dominoes[j]`.

**Example 1:**

```
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
```

**Constraints:**

- `1 <= dominoes.length <= 40000`
- `1 <= dominoes[i][j] <= 9`

#### 哈希表：

​		遍历多米诺骨牌组成的列表 dominoes，把每个多米诺骨牌 dominoes[i] 按照左小右大的规定调整好，再转换为整数 int 的形式存储在哈希表中。

​		遍历的过程中就可以同时统计有多少对等价的骨牌对了，因为我们已经规定好骨牌的形式，所以在进行哈希映射时是唯一的。

```c++
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        unordered_map<int, int> hash;
        for(auto &i : dominoes){
            if(i[0] > i[1])
                swap(i[0], i[1]);
            int cur = i[0] * 10 + i[1];
            ans += hash[cur];
            hash[cur]++;
        }
        return ans;
    }
};
```

