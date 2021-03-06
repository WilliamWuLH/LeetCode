## Combination Sum II

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

**Constraints:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

#### 回溯法 backtrack：

​		坑点：

​				何时判断组合总和是不是等于目标值（会影响到数组最后一个元素的判断）

​				最后的答案怎么去重？

```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans1;
        vector<vector<int>> ans;
        vector<int> num;
        backtrack(ans1, num, 0, 0, candidates, target);
        set<vector<int>>::iterator it;
        for(it=ans1.begin(); it!=ans1.end(); it++)
            ans.push_back(*it);
        return ans;
    }
    void backtrack(set<vector<int>> &ans, vector<int> &num, int sum, int pos, vector<int>& candidates, int target){
        if(sum == target){
            vector<int> temp = num;
            sort(temp.begin(), temp.begin()+temp.size());
            ans.insert(temp);
            return;
        }
        if(sum > target)
            return;
        if(pos < candidates.size()){
            num.push_back(candidates[pos]);
            sum += candidates[pos];
            backtrack(ans, num, sum, pos+1, candidates, target);
            num.pop_back();
            sum -= candidates[pos];
            backtrack(ans, num, sum, pos+1, candidates, target);
        }
        return;
    }
};
```

