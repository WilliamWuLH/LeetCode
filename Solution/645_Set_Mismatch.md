## Set Mismatch

You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one** number and **loss of another** number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return *them in the form of an array*.

**Example 1:**

```
Input: nums = [1,2,2,4]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [1,2]
```

**Constraints:**

- `2 <= nums.length <= 10^4`
- `1 <= nums[i] <= 10^4`

#### 遍历 + 统计：

​		集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

​		给定一个数组 nums 代表了集合 S 发生错误后的结果。需要找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

​		首先可以知道给定数组 nums 的大小 n，然后开辟一个大小为 n 的数组 count 用于统计每一个数的出现次数，遍历给定的数组 nums 并且记录 nums[i] 的出现次数在数组 count 中。

​		在数组 count 中，有 count[i] == 2 说明 i+1 是重复的元素，有 count[i] == 0 说明 i+1 是缺失元素。

```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int count[n];
        memset(count, 0, sizeof(int) * n);
        for(int i=0; i<n; i++)
            count[ nums[i] - 1 ]++;
        vector<int> ans(2, 0);
        for(int i=0; i<n; i++){
            if(count[i] == 2)
                ans[0] = i+1;
            if(count[i] == 0)
                ans[1] = i+1;
            if(ans[0] != 0 && ans[1] != 0)
                break;
        }
        return ans;
    }
};
```

#### 优化：开辟常数空间

​		在统计和记录给定数组 nums 中元素 nums[i] 出现次数时可以更新在数组 nums 上。

```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2, 0);
        for(int i=0; i<n; i++){
            int cur = abs( nums[i] ) - 1;
            if(nums[cur] < 0)
                ans[0] = cur+1;
            else
                nums[cur] = -nums[cur];
        }
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
};
```

