## Single Number

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

**Follow up:** Could you implement a solution with a linear runtime complexity and without using extra memory?

**Example 1:**

```
Input: nums = [2,2,1]
Output: 1
```

**Example 2:**

```
Input: nums = [4,1,2,1,2]
Output: 4
```

**Example 3:**

```
Input: nums = [1]
Output: 1
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

#### 先加后减：

​			出现一次就加上，再出现一次就减去，最后剩下的就是 Single Number。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        map<int, int> m;
        for(int i=0; i<len; i++){
            if(m[ nums[i] ] == 0){
                m[ nums[i] ] = 1;
                ans += nums[i];
            }
            else
                ans -= nums[i];
        }
        return ans;
    }
};
```

#### 位运算：

​			异或：a ^ 0 = a，a ^ a = 0

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for(int i=0; i<len; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
```

