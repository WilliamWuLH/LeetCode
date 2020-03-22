## Permutations

#### 回溯法：

​		使用回溯法。

​		额外的空间开销是  map<int,int> use，用于记录哪些元素已经被使用了。

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    map<int,int> use;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
    void dfs(int count, vector<int>& nums){
        if(count == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i < nums.size(); i++){
            if(use[i] != 1){
                temp.push_back(nums[i]);
                use[i] = 1;
                dfs(count+1, nums);
                temp.pop_back();
                use[i] = 0;
            }
        }
    }
};
```

