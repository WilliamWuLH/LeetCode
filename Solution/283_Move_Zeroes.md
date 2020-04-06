## Move Zeroes

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

