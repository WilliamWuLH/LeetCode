## Minimum Size Subarray Sum

Given an array of **n** positive integers and a positive integer **s**, find the minimal length of a **contiguous** subarray of which the sum ≥ **s**. If there isn't one, return 0 instead.

**Example:** 

```
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
```

**Follow up:**

If you have figured out the *O*(*n*) solution, try coding another solution of which the time complexity is *O*(*n* log *n*). 

#### 滑动窗口：

​		双指针实现滑动窗口，每个窗口都是符合条件的，找窗口最小的就对了。

```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, ans = INT_MAX;
        while(right < nums.size()){
            if(sum < s){
                sum += nums[right];
                right++;
            }
            while(sum >= s){
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

