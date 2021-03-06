## Longest Consecutive Sequence

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

**Follow up:** Could you implement the `O(n)` solution? 

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

**Constraints:**

- `0 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`

#### 哈希表 + 判断：

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> hash;
        int ans = 0;
        for(auto i : nums)
            hash[i] = 1;
        for(auto i : hash){
            if(! hash.count(i.first - 1)){
                int cur = 1;
                int thenum = i.first + 1;
                while(hash.count(thenum)){
                    cur++;
                    thenum++;
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
```

