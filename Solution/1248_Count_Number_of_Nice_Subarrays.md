## Count Number of Nice Subarrays

Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return *the number of **nice** sub-arrays*.

**Example 1:**

```
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

**Example 2:**

```
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
```

**Example 3:**

```
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
```

**Constraints:**

- `1 <= nums.length <= 50000`
- `1 <= nums[i] <= 10^5`
- `1 <= k <= nums.length`

#### 滑动窗口：

​		使用队列保存窗口中的每一个奇数的索引，以便滑动和计算。

​		每次进行窗口的滑动需要计算窗口前面的连续偶数个数和窗口后面的连续偶数个数，相乘可以得到该窗口所能构成的 「优美子数组」 。

​		重点难点在滑动窗口的开头和结尾部分，需要额外判断。

```c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0, before = 1, end = 0, count = 0;
        queue<int> q;
        q.push(-1);
        for(int i=0; i<len; i++){
            if(nums[i] % 2 == 0)
                continue;
            if(count < k){
                q.push(i);
                count++;
            }
            if(count == k){
                int start = q.front();
                q.pop();
                if(start != -1){
                    q.push(i);
                    ans += before * (i - end);
                }
                before = q.front() - start;
                end = i;
            }
        }
        if(count == k)
            ans += before * (len - end);
        return ans;
    }
};
```

