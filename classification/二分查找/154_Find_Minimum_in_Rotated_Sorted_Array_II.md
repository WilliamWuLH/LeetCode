## Find Minimum in Rotated Sorted Array II

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,4,4,5,6,7]` might become:

- `[4,5,6,7,0,1,4]` if it was rotated `4` times.
- `[0,1,4,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` that may contain **duplicates**, return *the minimum element of this array*.

**Example 1:**

```
Input: nums = [1,3,5]
Output: 1
```

**Example 2:**

```
Input: nums = [2,2,2,0,1]
Output: 0
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- `nums` is sorted and rotated between `1` and `n` times.

#### 二分查找：

​		定义左右指针：左指针指向当前包含答案的数组序列最左边（左指针所指的元素也包含在内），右指针指向当前包含答案的数组序列的最右边（右指针所指的元素也包含在内）。

进行二分查找，取此时左右指针所指数组序列的中轴指针 mid，有三种情况：

- nums\[mid] < nums\[r]：说明此时数组的右侧是升序有序的，所以可能包含最小值的区间在左侧（含中轴元素），所以令 r = mid。
- nums\[mid] > nums\[r]：说明此时数组的右侧是无序的，所以可能包含最小值的区间在右侧，并且不包含中轴元素，所以令 l = mid+1。
- 如果以上都不符合，那么就是 nums\[mid] == nums\[r]，可以去除此时的右侧元素，即令 r--。

最后区间只剩下一个元素，返回 nums[l]，就是答案。

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l < r){
            int mid = l+(r-l)/2;
            if(nums[mid] < nums[r])
                r = mid;
            else if(nums[mid] > nums[r])
                l = mid+1;
            else
                r--;
        }
        return nums[l];
    }
};
```

