## Subsets

Given an integer array `nums`, return *all possible subsets (the power set)*.

The solution set must not contain duplicate subsets.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

#### 回溯法：

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(0, temp, nums);
        return ans;
    }
    void backtrack(int pos, vector<int> temp, vector<int>& nums){
        ans.push_back(temp);
        for(int i=pos; i<nums.size(); i++){
            temp.push_back(nums[i]);
            backtrack(i+1, temp, nums);
            temp.pop_back();
        }
        return;
    }
};
```

#### 枚举法：

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int len = nums.size();
        ans.push_back(temp);
        for(int i=0; i<len; i++){
            int anslen = ans.size();
            for(int j=0; j<anslen; j++){
                temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
```

#### 前序遍历：

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        preorder(0, temp, nums);
        return ans;
    }
    void preorder(int pos, vector<int> temp, vector<int>& nums){
        if(pos >= nums.size()){
            ans.push_back(temp);
            return;
        }       
        preorder(pos+1, temp, nums);
        temp.push_back(nums[pos]);
        preorder(pos+1, temp, nums);
    }
};
```

