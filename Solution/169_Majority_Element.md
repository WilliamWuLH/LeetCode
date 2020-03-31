## Majority Element

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

