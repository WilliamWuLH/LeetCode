## Find First and Last Position of Element in Sorted Array

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

**Follow up:** Could you write an algorithm with `O(log n)` runtime complexity?

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

**Example 3:**

```
Input: nums = [], target = 0
Output: [-1,-1]
```

**Constraints:**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`
- `nums` is a non-decreasing array.
- `-109 <= target <= 109`

#### 二分法 + 边界判断 + 取值判断：

​				二分法的重点和难点主要为：

- 左右边界的取值，主要是右边界（ size 还是 size - 1 ）。
- while 循环的判断条件（ < 还是 <= ），这和左右边界的取值有关。
- 中间位置的计算，使用 left + (right - left)/2 可以避免溢出。
- 不要用 else，全部都用 else if 把情况说明清楚。
- 针对不同情况，左右边界应该如何收缩：这和一开始左右边界的取值有关
- 最后取值（取出位置或者是坐标）时，需要判断该位置是否有效（即该位置在合法范围内），并且需要判断该位置的值是否为目标数值。

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0,right = nums.size();
        vector<int> ans = {-1,-1};
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                right = mid;
            else if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid;
        }
        if(left < nums.size() && nums[left] == target)
            ans[0] = left;
        left = 0,right = nums.size();
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                left = mid+1;
            else if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid;
        }
        if(right-1 < nums.size() && nums[right-1] == target)
            ans[1] = right-1;
        return ans;
    }
};
```

