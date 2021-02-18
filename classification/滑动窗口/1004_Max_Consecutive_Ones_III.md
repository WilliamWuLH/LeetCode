## Max Consecutive Ones III

Given an array `A` of 0s and 1s, we may change up to `K` values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

**Example 1:**

```
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
```

**Example 2:**

```
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
```

**Note:**

1. `1 <= A.length <= 20000`
2. `0 <= K <= A.length`
3. `A[i]` is `0` or `1` 

#### 滑动窗口：双指针

​		题目给定一个由若干 `0` 和 `1` 组成的数组 `A`，我们最多可以将 `K` 个值从 0 变成 1 。要求返回仅包含 1 的最长（连续）子数组的长度。

​		由于是求最长（连续）子数组，所以可以考虑使用滑动窗口的思想来求解这道题，具体的代码实现可以使用双指针来模拟滑动窗口。我们使用一个变量 count0 来记录滑动窗口中的 0 的数目。

​		当此时右指针还没有到达数组末尾时，说明窗口还可以继续滑动，在窗口滑动过程中，首先判断滑动窗口内的 0 的数目是否符合 K 值的要求，即 count0 要小于等于 K，如果不满足，需要调整左指针，使左指针向右移动缩小窗口，使得窗口中的 0 的数目 count0 小于等于 K。接下来判断右指针，右指针在窗口滑动的过程中不断向右移动，我们需要判断右指针所指的数字是 0 或 1，是 0 的话需要增加窗口中的 0 的数目，即 count0 要加一。

​		注意，在滑动窗口不断滑动判断的过程中，我们要一直更新最长（连续）子数组的长度，即当滑动窗口中的子数组符合要求时，我们判断当前的子数组的长度是不是最长的长度。最终返回答案。

```c++
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0, l = 0, r = 0, count0 = 0;
        int n = A.size();
        while(r < n){
            while(count0 > K && l < r){
                if(A[l] == 0)
                    count0--;
                l++;
            }
            if(A[r] == 0)
                count0++;
            r++;
            if(count0 <= K)
                ans = max(ans, r-l);
        }
        return ans;
    }
};
```

