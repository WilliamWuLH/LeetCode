## Combinations

Given two integers *n* and *k*, return all possible combinations of *k* numbers out of 1 ... *n*.

You may return the answer in **any order**.

**Example 1:**

```
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

**Example 2:**

```
Input: n = 1, k = 1
Output: [[1]]
```

**Constraints:**

- `1 <= n <= 20`
- `1 <= k <= n`

#### 回溯法：

​			难点在于**去重**，其实就是一个序列中不同数字的排列顺序不一样。

​			我的做法是每次取比当前的数更大的数，这样就不会考虑到之前已经取过的值。

```c++
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> num;
        dfs(ans, num, n, k, 1);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int> &num, int n, int k, int pos){
        if(num.size() == k){
            ans.push_back(num);
            return;
        }
        for(int i=pos; i<=n; i++){
            num.push_back(i);
            dfs(ans, num, n, k, i+1);
            num.pop_back();
        }
    }
};
```

