## Subsets II

Given a collection of integers that might contain duplicates, ***nums\***, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

```
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```

#### 回溯法 + 去重：

​		回溯法可以遍历每一种子集的情况。

​		由于集合中元素有重复，通过在每一层判断是否有元素重复出现来进行去重，防止同一元素被多次使用，而导致出现重复的子集。

```c++
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        ans.push_back(subset);
        sort(nums.begin(), nums.end());
        backtrack(ans, nums, subset, 0);
        return ans;
    }
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &subset, int k){
        if(k >= nums.size())
            return;
        for(int i=k; i<nums.size(); i++){
            if(i > k && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            ans.push_back(subset);
            backtrack(ans, nums, subset, i+1);
            subset.pop_back();
        }
    }
};
```

