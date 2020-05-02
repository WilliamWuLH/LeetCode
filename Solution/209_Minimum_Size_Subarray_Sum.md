## Minimum Size Subarray Sum

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

