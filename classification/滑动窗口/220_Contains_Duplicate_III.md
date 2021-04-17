## Contains Duplicate III

Given an integer array `nums` and two integers `k` and `t`, return `true` if there are **two distinct indices** `i` and `j` in the array such that `abs(nums[i] - nums[j]) <= t` and `abs(i - j) <= k`.

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
```

**Example 3:**

```
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

**Constraints:**

- `0 <= nums.length <= 2 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^4`
- `0 <= t <= 2^31 - 1`

#### 滑动窗口 + 有序集合：

参考：

- [力扣官方题解](https://leetcode-cn.com/problems/contains-duplicate-iii/solution/cun-zai-zhong-fu-yuan-su-iii-by-leetcode-bbkt/)

- [set](http://www.cplusplus.com/reference/set/set/)

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> window;
        int n = nums.size();
        for(int i=0; i<n; i++){
            auto it = window.lower_bound(max(nums[i], INT_MIN+t)-t);
            if(it != window.end() &&  *it <= min(nums[i], INT_MAX-t)+t)
                return true;
            window.insert(nums[i]);
            if(i >= k)
                window.erase(nums[i-k]);
        }
        return false;
    }
};
```

