## 3Sum Closest

#### 排序 + 双指针遍历：

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len-2; i++ ){
            if( i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i+1,right = len-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(ans - target) > abs(sum - target))
                    ans = sum;
                if(sum > target)
                    while(left < --right && nums[right] == nums[right+1]);
                else if(sum < target)
                    while(++left < right && nums[left] == nums[left-1]);
                else
                    return sum;
            }
        }
        return ans;
    }
};
```

