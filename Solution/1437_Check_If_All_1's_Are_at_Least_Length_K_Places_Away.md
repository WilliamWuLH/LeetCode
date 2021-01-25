## Check If All 1's Are at Least Length K Places Away

Given an array `nums` of 0s and 1s and an integer `k`, return `True` if all 1's are at least `k` places away from each other, otherwise return `False`.

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png)**

```
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
```

**Example 2:**

**![img](https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png)**

```
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
```

**Example 3:**

```
Input: nums = [1,1,1,1,1], k = 0
Output: true
```

**Example 4:**

```
Input: nums = [0,1,0,1], k = 1
Output: true
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= k <= nums.length`
- `nums[i]` is `0` or `1`

#### 遍历 + 记录前一个位置：

​		本题没有什么难度，就是直接遍历，在遍历的过程中同时判断是否符合所有 1 都至少相隔 k 个元素。

​		我们进行判断就需要记录前一个 1 的位置，根据题目给定的数据范围，我们可以给这个前一个位置进行初始化，同时在遍历的过程中不断更新，以便后续的判断。

```c++
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = -10e6;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(i - pre - 1 < k)
                    return false;
                pre = i;
            }
        }
        return true;
    }
};
```

