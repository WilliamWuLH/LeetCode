## Permutations II

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Constraints:**

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`

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

