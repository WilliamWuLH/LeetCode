## Triangle

#### 回溯法：

​		遍历所有情况，找最小值。

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        backtrack(triangle, 0, 0, ans, 0);
        return ans;
    }
    void backtrack(vector<vector<int>>& triangle, int v, int h, int &ans, int count){
        if(v == triangle.size()){
            if(count <= ans)
                ans = count;
            return;
        }
        count += triangle[v][h];
        backtrack(triangle, v+1, h, ans, count);
        backtrack(triangle, v+1, h+1, ans, count);
        count -= triangle[v][h];
        return;
    }
};
```

#### 动态规划：

​		详见代码，很好理解。

​		注意三角形的两条左右斜边最好是特殊考虑。

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<triangle.size(); i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for(int j=1; j<i; j++)
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
```

