## Largest Number

Given a list of non-negative integers `nums`, arrange them such that they form the largest number.

**Note:** The result may be very large, so you need to return a string instead of an integer.

**Example 1:**

```
Input: nums = [10,2]
Output: "210"
```

**Example 2:**

```
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

**Example 3:**

```
Input: nums = [1]
Output: "1"
```

**Example 4:**

```
Input: nums = [10]
Output: "10"
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 109`

#### 排序 + 组合：

​		给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

​		排序：把大的数排在前面（可以组合成更大的数）

​		组合：把数转成字符串并进行组合。

```c++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> s;
        for(auto &i : nums)
            s.emplace_back(to_string(i));
        sort(s.begin(), s.end(), [&](const auto &a, const auto &b){
            return a + b > b + a;
        });
        for(auto &i:s)
            ans += i;
        return ans[0] == '0' ? "0" : ans;
    }
};
```

