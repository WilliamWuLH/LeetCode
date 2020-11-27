## Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `0 <= nums[i][j] <= 10^5`

#### 贪心法：

​				从数组的尾部开始往前找，找到可以到达最后一个位置的，离第一个位置最近的位置。

​				最后判断这个位置是不是数组的第一个位置。

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int pos = len-1;
        for(int i=len-1; i>=0; i--){
            if(i+nums[i] >= pos)
                pos = i;
        }
        return pos == 0;
    }
};
```

