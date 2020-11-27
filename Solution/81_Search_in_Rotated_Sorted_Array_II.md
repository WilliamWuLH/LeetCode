## Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,0,1,2,2,5,6]` might become `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return `true`, otherwise return `false`.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Follow up:**

- This is a follow up problem to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), where `nums` may contain duplicates.
- Would this affect the run-time complexity? How and why?

#### 难点在于存在重复数字：

​		根据中间索引可以将这个旋转排序数组分成有序的一边和乱序的一边。

​		难就难在它存在重复数字，无法正常判断它哪一边是有序的，哪一边是乱序的。

​		通过当判断左索引和中间索引相同时，左索引向右移动一位，可以解除这种判断困难，同时对于右索引也是一样的套路，这是技巧所在。

```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(nums.size() == 0)
            return false;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
                return true;
            if(nums[left] == nums[mid]){
                left++;
                continue;
            }
            else if(nums[mid] > target){
                if(mid-1 >=0 && nums[left] <= nums[mid-1] && nums[left] > target)
                    left = mid+1;
                else
                    right = mid-1;
            }
            else if(nums[mid] < target){
                if(mid+1 < nums.size() && nums[mid+1] <= nums[right] && nums[right] < target)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        if(nums[left] == target)
            return true;
        else
            return false;
    }
};
```

