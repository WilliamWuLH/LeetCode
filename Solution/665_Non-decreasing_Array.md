## Non-decreasing Array

Given an array `nums` with `n` integers, your task is to check if it could become non-decreasing by modifying **at most one element**.

We define an array is non-decreasing if `nums[i] <= nums[i + 1]` holds for every `i` (**0-based**) such that (`0 <= i <= n - 2`).

**Example 1:**

```
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
```

**Example 2:**

```
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^4`
- `-10^5 <= nums[i] <= 10^5`

#### 线性扫描 + 计数 + 判断：

​		在最多改变 1 个元素的情况下，判断数组能否变成一个非递减数列。

​		首先我们找到不符合非递减的元素对，如果出现多组不符合非递减的元素对，则直接返回 false。

​		如果当前判断到有一组元素对不符合非递减，判断此时位于后面的那个元素 nums[i+1] 和位于之前一个的元素 nums[i-1] 的大小关系，如果 nums[i+1] < nums[i-1]，则说明此时如果要改变一个元素就只能改变 nums[i+1]，所以进行修改 nums[i+1] = nums[i]，再继续进行线性扫描判断。

```c++
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
                if(count > 1)
                    return false;
                if(count > 0 && i > 0 && nums[i+1] < nums[i-1])
                    nums[i+1] = nums[i];
            }
        }
        return true;
    }
};
```

