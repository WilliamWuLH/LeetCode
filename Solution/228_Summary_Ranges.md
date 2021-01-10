## Summary Ranges

You are given a **sorted unique** integer array `nums`.

Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.

Each range `[a,b]` in the list should be output as:

- `"a->b"` if `a != b`
- `"a"` if `a == b`

**Example 1:**

```
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```

**Example 2:**

```
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
```

**Example 3:**

```
Input: nums = []
Output: []
```

**Example 4:**

```
Input: nums = [-1]
Output: ["-1"]
```

**Example 5:**

```
Input: nums = [0]
Output: ["0"]
```

**Constraints:**

- `0 <= nums.length <= 20`
- `-2^31 <= nums[i] <= 2^31 - 1`
- All the values of `nums` are **unique**.
- `nums` is sorted in ascending order.

#### 记录区间的起止点：

​		每个区间的最开始都是只有一个数字，都是从一个数字开始的，所以设置区间的起点和终点都是这个数字。

​		遍历数组元素，如果数组元素是按顺序连续排列在数组中的，则可以规约为一个区间，因为起点是确定的，所以只需要不断更新终点的值就可以了。当数组元素不连续时，就需要分成不同的区间，也就是需要更新新区间的起止点，再进行下一步的判断。

​		当区间的起止点是同一个数字时，说明当前区间就只有这一个数字，当区间的起止点不同时，就需要写成 "a->b" 的形式。

**关于具体实现时的一些小技巧，详见代码：**

```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n <= 0)
            return ans;
        int start = nums[0], end = nums[0];
        for(int i=1; i<=n; i++){
            if(i < n && nums[i] == nums[i-1] + 1)
                end = nums[i];
            else{
                if(start == end)
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(end));
                if(i < n)
                    start = end = nums[i];
            }
        }
        return ans;
    }
};
```

