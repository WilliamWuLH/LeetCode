## Find Pivot Index

Given an array of integers `nums`, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

**Example 1:**

```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```

**Constraints:**

- The length of `nums` will be in the range `[0, 10000]`.
- Each element `nums[i]` will be an integer in the range `[-1000, 1000]`.

#### 遍历 + 求和：

​		这道题的思路很简单，就是遍历和求和，找到数组的中心索引：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

具体实现：

​		首先，计算整个数组的总和 sum。接着，从数组的第一个元素（最左侧）开始遍历，判断此时数组的左侧所有元素相加的和是否等于右侧所有元素相加的和。此时，我们可以设定数组的左侧所有元素相加的和为 cur，初始时 cur 为 0，每遍历一个元素就把这个元素加到 cur 上，在遍历判断的同时完成对左侧所有元素相加的和的更新。此时，数组右侧所有元素相加的和为 sum - cur - nums\[i\]，所以可以判断是否相等，如果相等则返回 i，不相等则继续遍历下一个元素，直到最后一个元素（最右侧）。

​		如果没有一个符合的情况则返回 -1。

```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, n = nums.size(), cur = 0;
        for(auto &i : nums)
            sum += i;
        for(int i=0; i<n; i++){
            if(cur == sum - cur - nums[i])
                return i;
            cur += nums[i];
        }
        return -1;
    }
};
```

