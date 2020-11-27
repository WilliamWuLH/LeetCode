## Two Sum II - Input array is sorted

Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

**Note:**

- Your returned answers (both index1 and index2) are not zero-based.
- You may assume that each input would have *exactly* one solution and you may not use the *same* element twice.

**Example 1:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

**Example 2:**

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
```

**Example 3:**

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
```

**Constraints:**

- `2 <= nums.length <= 3 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `nums` is sorted in **increasing order**.
- `-1000 <= target <= 1000`

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

