## Maximum Average Subarray I

Given an array consisting of `n` integers, find the contiguous subarray of given length `k` that has the maximum average value. And you need to output the maximum average value.

**Example 1:**

```
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
```

**Note:**

1. 1 <= `k` <= `n` <= 30,000.
2. Elements of the given array will be in the range [-10,000, 10,000].

#### 滑动窗口：

​		题目给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

​		看到**长度为 k 的连续子数组**，就知道这是一道滑动窗口的题目。

​		很简单，我们维护一个平均数的最大值，然后每次滑动窗口，就是去除窗口中最前面的那个数，然后添加窗口后面的第一个数，计算此时的平均数并更新答案。

```c++
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<k; i++)
            sum += nums[i];
        ans = (double)sum / k;
        for(int i=0; i+k<n; i++){
            sum = sum - nums[i] + nums[i+k];
            ans = max(ans, (double)sum / k);
        }
        return ans;
    }
};
```

