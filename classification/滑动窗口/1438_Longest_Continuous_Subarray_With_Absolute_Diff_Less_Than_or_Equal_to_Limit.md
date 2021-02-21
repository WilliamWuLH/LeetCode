## Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers `nums` and an integer `limit`, return the size of the longest **non-empty** subarray such that the absolute difference between any two elements of this subarray is less than or equal to `limit`*.*

**Example 1:**

```
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
```

**Example 2:**

```
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
```

**Example 3:**

```
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `0 <= limit <= 10^9`

#### 滑动窗口 + 有序集合：

​		可以枚举每一个位置作为右端点，找到其对应的最靠左的左端点，满足区间中最大值与最小值的差不超过 limit。注意到随着右端点向右移动，左端点也将向右移动，于是我们可以使用滑动窗口解决本题。

​		为了方便统计当前窗口内的最大值与最小值，我们可以使用平衡树。

**参考：**

- [力扣官方题解](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solution/jue-dui-chai-bu-chao-guo-xian-zhi-de-zui-5bki/)

- [multiset](http://www.cplusplus.com/reference/set/multiset/)

- [multiset用法总结](https://blog.csdn.net/sodacoco/article/details/84798621)

```c++
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, r = 0, l = 0, n = nums.size();
        multiset<int> s;
        while(r < n){
            s.insert(nums[r]);
            while(*s.rbegin() - *s.begin() > limit)
                s.erase(s.find(nums[l++]));
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
```

