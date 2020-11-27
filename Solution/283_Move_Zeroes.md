## Move Zeroes

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Example:**

```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Note**:

1. You must do this **in-place** without making a copy of the array.
2. Minimize the total number of operations.

#### 删去 0 + 尾部添加 0：

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int pos = 0;
        while(len){
            if(nums[pos] == 0){
                nums.erase(nums.begin()+pos);
                nums.push_back(0);
            }
            else
                pos++;
            len--;
        }
    }
};
```

