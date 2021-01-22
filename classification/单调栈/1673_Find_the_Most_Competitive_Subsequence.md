## Find the Most Competitive Subsequence

Given an integer array `nums` and a positive integer `k`, return *the most **competitive** subsequence of* `nums` *of size* `k`.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence `a` is more **competitive** than a subsequence `b` (of the same length) if in the first position where `a` and `b` differ, subsequence `a` has a number **less** than the corresponding number in `b`. For example, `[1,3,4]` is more competitive than `[1,3,5]` because the first position they differ is at the final number, and `4` is less than `5`.

**Example 1:**

```
Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
```

**Example 2:**

```
Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`
- `1 <= k <= nums.length`

#### 感悟：这种  去除字符串（数组等）中的部分元素  并  返回最小值（最小字典序）  的题目，一般都用  单调栈  的思想。

#### 不同点：去除字符串（数组等）中元素的条件、单调栈中弹出栈顶元素的条件、添加单调栈栈顶元素的条件

#### 单调栈：

​		先看看题目：

​		给一个整数数组 nums 和一个正整数 k ，返回长度为 k 且最具 竞争力 的 nums 子序列。

​		数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。

​		在子序列 a 和子序列 b 第一个不相同的位置上，如果 a 中的数字小于 b 中对应的数字，那么称子序列 a 比子序列 b（相同长度下）更具竞争力 。 例如，[1,3,4] 比 [1,3,5] 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， 4 小于 5 。

​		读完题目，其实所谓**更具竞争力的子序列**，其实就是**子序列所表示的数字更小**。因为在两个子序列中，数字不相同的位置数字小的那个子序列所表示的数值肯定更小，所以在本题中也更具竞争力。

​		并且，本题中返回长度为 k 的子序列，其实就是**从原数组中删除 nums.size() - k 个元素**之后得到的序列。

​		**所以，本题可以使用单调栈。**

​		->  **去除数组中元素的条件**：无

​		->  **单调栈中弹出栈顶元素的条件**：数组中还有剩余的元素可以被删除，且单调栈中已经有元素，并且单调栈中栈顶元素大于当前遍历到的数字。

​		->  **添加单调栈栈顶元素的条件**：无，遍历到的当前数字小于单调栈栈顶元素时可以直接添加进单调栈。

​		遍历结束之后还需要判断数组中是否还有剩余的元素可以被删除，如果有则说明单调栈中的元素过多，应该 pop_back() 元素直到满足子序列的返回长度。

​		最后的单调栈就是答案。

```c++
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        k = nums.size() - k;
        for(auto &i : nums){
            while(k && !ans.empty() && ans.back() > i){
                ans.pop_back();
                k--;
            }
            ans.emplace_back(i);
        }
        while(k--)
            ans.pop_back();
        return ans;
    }
};
```

