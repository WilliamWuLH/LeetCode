## Sort Colors

#### 统计颜色个数 + 重新排列：

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0,0,0};
        int len = nums.size();
        for(int i=0; i<len; i++){
            count[nums[i]]++;
        }
        int temp = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<count[i]; j++){
                nums[temp] = i;
                temp++;                           
            }
        }
    }
};
```

#### 三指针：

​			一个指针指向 0 的尾部，一个指针指向 2 的开头，一个指针进行遍历。

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len-1, curr = 0;
        while(curr <= right){
            if(nums[curr] == 0)
                swap(nums[curr++], nums[left++]);
            else if(nums[curr] == 2)
                swap(nums[curr], nums[right--]);
            else
                curr++;
        }
    }
};
```

