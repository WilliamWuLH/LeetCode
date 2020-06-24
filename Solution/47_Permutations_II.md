## Permutations II

#### 深度优先搜索 + 哈希表去重：

```c++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        map<vector<int>, int> repeat;
        vector<int> used(nums.size(), 0);
        vector<int> temp;
        dfs(ans, repeat, used, temp, nums);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, map<vector<int>, int> &repeat, vector<int> &used, vector<int> &temp,vector<int>& nums){
        if(temp.size() == nums.size()){
            if(repeat.count(temp) == 0){
                ans.push_back(temp);
                repeat[temp]++;
            }
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i] == 0){
                temp.push_back(nums[i]);
                used[i] = 1;
                dfs(ans, repeat, used, temp, nums);
                temp.pop_back();
                used[i] = 0;
            }
        }
    }
};
```

