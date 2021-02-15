## The K Weakest Rows in a Matrix

Given a `m * n` matrix `mat` of *ones* (representing soldiers) and *zeros* (representing civilians), return the indexes of the `k` weakest rows in the matrix ordered from the weakest to the strongest.

A row ***i*** is weaker than row ***j***, if the number of soldiers in row ***i*** is less than the number of soldiers in row ***j***, or they have the same number of soldiers but ***i*** is less than ***j***. Soldiers are **always** stand in the frontier of a row, that is, always *ones* may appear first and then *zeros*.

**Example 1:**

```
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
```

**Example 2:**

```
Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `2 <= n, m <= 100`
- `1 <= k <= m`
- `matrix[i][j]` is either 0 **or** 1.

#### 统计 + 排序：

​		首先，统计每一行中军人的数量，也就是每一行中 1 的数量，由于军人总是排在一行中的靠前位置，也就是说 1 总是出现在 0 之前，所以当我们统计到出现 0 时就可以结束统计。我们把统计结果组织成 \< 军人数量 , 行号 \> 的形式。

​		接下来就是排序，首先根据军人数量的大小进行排序，当军人数量一样时再根据行号的大小进行排序。

​		最后的答案取出前 k 个的行号。

```c++
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<tuple<int, int>> count;
        int n = mat.size();
        for(int i=0; i<n; i++){
            int temp = 0;
            for(auto &j : mat[i])
                if(j == 1)
                    temp++;
                else
                    break;
            count.emplace_back(tuple<int, int>(temp, i));
        }
        // sort(count.begin(), count.end());
        sort(count.begin(), count.end(), [&](const auto &a, const auto &b){
            auto && [a1, a2] = a;
            auto && [b1, b2] = b;
            if(a1 == b1)
                return a2 < b2;
            return a1 < b1;
        });
        for(int i=0; i<k; i++){
            auto & [v1, v2] = count[i];
            ans.emplace_back(v2);
        }
        return ans;
    }
};
```

