## Majority Element

Given an array of size *n*, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.

**Example 1:**

```
Input: [3,2,3]
Output: 3
```

**Example 2:**

```
Input: [2,2,1,1,1,2,2]
Output: 2
```

#### 哈希计数：

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        map<int, int> m;
        for(int i=0; i<len; i++){
            m[ nums[i] ]++;
            if(m[ nums[i] ] > len/2)
                return nums[i];
        }
        return -1;
    }
};
```

#### 排序取中间：

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[ nums.size()/2 ];
    }
};
```

#### Moore 摩尔投票法：

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans;
        for(auto n : nums){
            if(count == 0)
                ans = n;
            if(ans == n)
                count++;
            else
                count--;
        }
        return ans;
    }
};
```

