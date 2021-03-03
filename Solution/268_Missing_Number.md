## Missing Number

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

**Example 4:**

```
Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

#### 方法一：遍历 + 操作题目给定数组

​		找到缺失的那个数，先遍历一次题目给定的数组，把数组中已经出现的数的索引的元素进行操作，加上一个偏移量，表示这个位置的数已经出现过。

​		然后再进行一次遍历，找到没有被操作过的位置，这个位置就是那个没有出现的数。

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ans = n, bias = 10001;
        for(int i=0; i<n; i++){
            int cur = nums[i] < bias ? nums[i] : nums[i] - bias;
            if(cur == n)
                ans += bias;
            else
                nums[cur] += bias;
        }
        if(ans < bias)
            return ans;
        for(int i=0; i<n; i++){
            if(nums[i] < bias){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
```

#### 方法二：求和公式

​		通过求和公式求出从 0 加到 n 的和（一共 n + 1 个数），然后再减去题目给定数组中的每一个数，最后的结果就是缺失的那个数。

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = ( (0 + n) * ( n + 1 ) ) >> 1;
        for(auto &i : nums)
            ans -= i;
        return ans;
    }
};
```

