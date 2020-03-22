## Combination Sum

#### 回溯法（ DFS 深度优先搜索 ）：

​			首先将给定的数组进行排序，方便后面的判断以提高性能。

​			回溯法，其实也就是 DFS 深度优先搜索，也就是递归。

​			递归就需要有一个目标数值，有一个判断返回的条件。

​			判断递归返回的条件是建立在目标数值上的，在本题中是使得目标数值为 0。

​			目标数值为 0 说明找到了一个可行的答案，需要将答案进行保存。

​			数组按从小到大的顺序进行排序，从数组的尾部（此时的最大值）开始进行讨论：

- 如果此时数组的元素数值大于目标数值，则跳过该元素，讨论下一个元素（数值更小的）。
- 如果此时数组的元素数值小于等于目标数值，则说明该元素可能是可以组成目标数值的，使目标数值减去该元素数值得到新的目标数值，并且在可能的答案中添加该元素，进入下一轮递归。
- 递归返回后，需要从可能的答案中删去该元素，即“回溯”。

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int len = candidates.size();
        dfs(target, len-1, candidates);
        return ans;
    }
    void dfs(int target, int pos, vector<int>& candidates){
        if(target == 0){
            ans.push_back(nums);
            return;
        }
        for(int i = pos; i >= 0; i--){
            if(candidates[i] > target)
                continue;
            nums.push_back(candidates[i]);
            dfs(target-candidates[i], i, candidates);
            nums.pop_back();
        }
    }
};
```

