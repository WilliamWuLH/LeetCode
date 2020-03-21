## Search in Rotated Sorted Array

#### 二分查找：

​		由于该“旋转有序数组”的特性，在对其进行划分时，划分出来的两个部分一定有一部分是完全有序的，另一部分是部分有序的。

​		根据这个特性，我们可以取出两个部分中完全有序的那一部分进行讨论：

​				由于数组是完全有序的，所以可以通过判断大小知道目标数字是否在这一部分。

​				如果目标数字不在完全有序的那一部分，那么一定在另一部分。

​		通过上述的判断可以进行二分查找，不断缩小查找范围，直到找到目标数字的位置或者没找到目标数字。

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        while(left <= right){
            if(left == right){
                if(nums[left] == target)
                    return left;
                else
                    return -1;
            }
            int mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid;
                    continue;
                }
                else{
                    left = mid+1;
                    continue;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid+1;
                    continue;
                }
                else{
                    right = mid;
                    continue;
                }
            }
        }
        return -1;
    }
};
```

