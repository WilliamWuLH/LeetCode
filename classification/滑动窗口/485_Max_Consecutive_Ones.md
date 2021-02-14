## Max Consecutive Ones

Given a binary array, find the maximum number of consecutive 1s in this array.

**Example 1:**

```
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
```

**Note:**

- The input array will only contain `0` and `1`.
- The length of input array is a positive integer and will not exceed 10,000

#### 滑动窗口：双指针

​		定义左右指针，左指针指向连续 1 的起始点，右指针指向当前连续 1 的终点，不断向右移动右指针，判断当前右指针指向的数字是不是 1，如果是则更新当前最大连续 1 的个数，如果不是则更新当前左指针的位置，一直到数组结束。

```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = -1, r = 0, n = nums.size(), ans = 0;
        while(r < n){
            if(nums[r] == 1)
                ans = max(ans, r-l);
            else
                l = r;
            r++;
        }
        return ans;
    }
};
```

