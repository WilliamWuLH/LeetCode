## Target Sum

#### 深度优先搜索 DFS：

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        dfs(ans, 0, 0, nums, S);
        return ans;
    }
    void dfs(int &ans, int pos, int sum, vector<int>& nums, int S){
        if(pos == nums.size()-1){
            if(sum + nums[pos] == S)
                ans++;
            if(sum - nums[pos] == S)
                ans++;
            return;
        }
        dfs(ans, pos+1, sum+nums[pos], nums, S);
        dfs(ans, pos+1, sum-nums[pos], nums, S);
    }
};
```

