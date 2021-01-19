## Maximum Product of Three Numbers

Given an integer array `nums`, *find three numbers whose product is maximum and return the maximum product*.

**Example 1:**

```
Input: nums = [1,2,3]
Output: 6
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 24
```

**Example 3:**

```
Input: nums = [-1,-2,-3]
Output: -6
```

**Constraints:**

- `3 <= nums.length <= 10^4`
- `-1000 <= nums[i] <= 1000`

#### 线性扫描：

​		如果数组中全是非负数，则排序后最大的三个数相乘即为最大乘积；如果全是非正数，则最大的三个数相乘同样也为最大乘积。

​		如果数组中有正数有负数，则最大乘积既可能是三个最大正数的乘积，也可能是两个最小负数（即绝对值最大）与最大正数的乘积。

​		综上，分别求出三个最大正数的乘积，以及两个最小负数与最大正数的乘积，二者之间的最大值即为所求答案。

```c++
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(auto &i : nums){
            if(i < min1){
                min2 = min1;
                min1 = i;
            }
            else if(i < min2)
                min2 = i;
            if(i > max1){
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if(i > max2){
                max3 = max2;
                max2 = i;
            }
            else if(i > max3){
                max3 = i;
            }
        }
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
```

