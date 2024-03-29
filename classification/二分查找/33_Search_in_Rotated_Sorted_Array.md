## Search in Rotated Sorted Array

You are given an integer array `nums` sorted in ascending order, and an integer `target`.

Suppose that `nums` is rotated at some pivot unknown to you beforehand (i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

*If `target` is found in the array return its index, otherwise, return `-1`.*

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1
```

**Constraints:**

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are **unique**.
- `nums` is guranteed to be rotated at some pivot.
- `-10^4 <= target <= 10^4`

#### 二分查找：

​		由于该“旋转有序数组”的特性，在对其进行划分时，划分出来的两个部分一定有一部分是完全有序的，另一部分是部分有序的。

​		根据这个特性，我们可以取出两个部分中完全有序的那一部分进行讨论：

​				由于数组是完全有序的，所以可以通过判断大小知道目标数字是否在这一部分。

​				如果目标数字不在完全有序的那一部分，那么一定在另一部分。

​		通过上述的判断可以进行二分查找，不断缩小查找范围，直到找到目标数字的位置或者没找到目标数字。

#### 2021.4.7 更新代码：更简洁可读

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) * 0.5;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[l]){
                if(target < nums[l] || target > nums[mid])
                    l = mid+1;
                else
                    r = mid;
            }
            else if(nums[r-1] >= nums[mid]){
                if(target < nums[mid] || target > nums[r-1])
                    r = mid;
                else
                    l = mid+1;
            }
        }
        return nums[r-1] == target ? l : -1;
    }
};
```

