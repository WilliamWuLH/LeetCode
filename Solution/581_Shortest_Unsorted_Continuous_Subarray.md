## Shortest Unsorted Continuous Subarray

Given an integer array `nums`, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return *the shortest such subarray and output its length*.

**Example 1:**

```
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 0
```

**Example 3:**

```
Input: nums = [1]
Output: 0
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^5 <= nums[i] <= 10^5`

#### 排序找不同：

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy;
        copy = nums;
        sort(copy.begin(), copy.end());
        int head = 0, tail = nums.size()-1;
        while(head <= tail && copy[head] == nums[head])
            head++;
        while(head <= tail && copy[tail] == nums[tail])
            tail--;
        return tail-head+1;
    }
};
```

