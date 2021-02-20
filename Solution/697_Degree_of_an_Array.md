## Degree of an Array

Given a non-empty array of non-negative integers `nums`, the **degree** of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of `nums`, that has the same degree as `nums`.

**Example 1:**

```
Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
```

**Example 2:**

```
Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
```

**Constraints:**

- `nums.length` will be between 1 and 50,000.
- `nums[i]` will be an integer between 0 and 49,999.

#### 哈希表：

​		题目给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。我们需要在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

​		所以我们需要统计在数组 nums 中每一个元素的出现频数和第一次出现的位置，可以使用哈希表对每一个元素的信息进行存储。在遍历数组 nums 的过程中我们可以一边更新各个元素信息的哈希表，一边判断当前数组的度（数组里任一元素出现频数的最大值），并且根据元素的第一次出现位置计算最短连续子数组的长度。

```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, tuple<int, int>> hash;
        int n = nums.size();
        int maxDegree = 0, minLen = INT_MAX;
        for(int i=0; i<n; i++){
            if(hash.count(nums[i]) == 0){
                tuple<int, int> cur(1, i);
                hash[nums[i]] = cur;
            }
            else
                get<0>(hash[nums[i]])++;
            auto & [degree, start] = hash[nums[i]];
            if(degree == maxDegree)
                minLen = min(minLen, i - start + 1);
            else if(degree > maxDegree){
                minLen = i - start + 1;
                maxDegree = degree;
            }
        }
        return minLen;
    }
};
```

