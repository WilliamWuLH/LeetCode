## Permutations

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**

```
Input: nums = [1]
Output: [[1]]
```

**Constraints:**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.

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

