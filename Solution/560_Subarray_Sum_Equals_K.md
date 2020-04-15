## Subarray Sum Equals K

#### 前缀和 or 累计和：

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == k)
                    ans++;
            }
        }
        return ans;
    }
};
```

