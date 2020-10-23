## Two Sum II - Input array is sorted

#### 双指针：

​		由于是有序数组，所以可以使用双指针前后夹击的方法。

​		双指针：一个指针从有序数组的首部开始，另一个指针从有序数组的尾部开始。

​		前后夹击：由于是有序数组，所以当双指针所指向的值相加不等于目标数时，如果是比目标数更大，则尾部的指针向前移一位，指向更小的数；如果是比目标数更小时，首部指针向后移一位，指向更大的数。以此实现前后夹击，找到最终答案。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(numbers[left] + numbers[right] != target){
            int sum = numbers[left]+numbers[right];
            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            if(left >= right)
                break;
        }
        return {left+1, right+1};
    }
};
```

