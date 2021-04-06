## Remove Duplicates from Sorted Array II

Given a sorted array *nums*, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that duplicates appeared at most *twice* and return the new length.

Do not allocate extra space for another array; you must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

**Clarification:**

Confused why the returned value is an integer, but your answer is an array?

Note that the input array is passed in by **reference**, which means a modification to the input array will be known to the caller.

Internally you can think of this:

```
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

**Example 1:**

```
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3]
Explanation: Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what you leave beyond the returned length.
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3]
Explanation: Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively. It doesn't matter what values are set beyond the returned length.
```

**Constraints:**

- `0 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in ascending order.

#### 2021.4.6 每日一题

#### 双指针

​		这里的双指针使用方法有点像是滑动窗口。

​		由于这里的数组是有序数组，所以在去除重复项的时候非常简单，因为重复项也需要遵循数组的有序，重复项都是相邻排列在一起的。所以可以设置一个指针 cur 指向当前数字的第一次出现的位置，另一个指针 next 不断向后移动，分为多种情况，具体看代码吧，不难理解。

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if(l <= 2)
            return l;
        int cur = 0, next = 1;
        while(next != nums.size()){
            if(next - cur == 1){
                if(nums[cur] != nums[next])
                    cur = next;
                next++;
            }
            else{
                if(nums[cur] == nums[next])
                    nums.erase(nums.begin()+next);
                else{
                    cur = next;
                    next++;
                }
            }
        }
        return nums.size();
    }
};
```



#### 排序数组的元素判断：

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int i=1;
        while(i<nums.size()){
            if(count == 2 && nums[i-1] == nums[i]){
                nums.erase(nums.begin()+i);
                continue;
            }
            else if(nums[i-1] == nums[i])
                count++;
            else
                count = 1;
            i++;
        }
        return nums.size();
    }
};
```

