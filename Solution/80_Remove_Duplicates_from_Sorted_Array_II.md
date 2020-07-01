## Remove Duplicates from Sorted Array II

#### 排序数组的元素判断：

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int i=1;
        while(i<nums.size()){
            if(count == 2 && nums[i-1] == nums[i]){
                nums.erase(nums.begin()+i);
                continue;
            }
            else if(nums[i-1] == nums[i])
                count++;
            else
                count = 1;
            i++;
        }
        return nums.size();
    }
};
```

