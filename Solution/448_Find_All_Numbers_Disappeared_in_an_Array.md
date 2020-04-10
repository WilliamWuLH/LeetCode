## Find All Numbers Disappeared in an Array

#### 操作原数组：

​		遍历原数组，判断每个数组元素的绝对值，把该数组元素对应的数组索引的值改为负数。

​		再进行一次遍历，数组元素是正数的索引值就是未出现的数字。

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++)
            if(nums[ abs(nums[i])-1 ] > 0)
            nums[ abs(nums[i])-1 ] *= -1;
        for(int i=0; i<n; i++)
            if(nums[i] > 0)
                ans.push_back(i+1);
        return ans;
    }
};
```

