## Max Number of K-Sum Pairs

You are given an integer array `nums` and an integer `k`.

In one operation, you can pick two numbers from the array whose sum equals `k` and remove them from the array.

Return *the maximum number of operations you can perform on the array*.

**Example 1:**

```
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
```

**Example 2:**

```
Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`

#### 排序 + 双指针：

​		本题有点类似那种 n 数之和的问题。

​		给定一个整数数组 nums 和一个整数 k 。每一步操作中，需要从数组中选出和为 k 的两个整数，并将它们移出数组。返回可以对数组执行的最大操作数。

​		所以，我们可以先对数组进行排序，让双指针的移动变得有序。

​		然后，我们定义左右指针，左指针指向现在数组中最小的元素，右指针指向现在数组中最大的元素。不断判断左右指针所指的数字相加后的结果，情况如下：

1. 左右指针所指数字相加后等于 k，找到一个操作，ans++，然后左指针向右移动 l++，右指针向左移动 r--。
2. 左右指针所指数字相加后小于 k，说明此时左指针所指的数字太小了，左指针向右移动 l++。
3. 左右指针所指数字相加后大于 k，说明此时右指针所指的数字太大了，右指针向左移动 r--。

不断判断左右指针，直到左右指针相遇时停止，即 l = r。

最终返回答案 ans，即相加等于 k 的数目，也是可操作数。

```c++
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1, ans = 0;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == k){
                l++;
                r--;
                ans++;
            }
            else if(sum > k)
                r--;
            else if(sum < k)
                l++;
        }
        return ans;
    }
};
```

