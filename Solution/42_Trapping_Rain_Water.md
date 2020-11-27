## Trapping Rain Water

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

- `n == height.length`
- `0 <= n <= 3 * 10^4`
- `0 <= height[i] <= 10^5`

#### 按列计算 + 动态规划：

​			按列计算是指每一次只讨论一个列，根据该列左边高度最高的墙和右边高度最高的墙，计算该列可不可以存水，能存多少水。

​			首先判断能不能存水，需要左边最高墙和右边最高墙的高度都高于当前列的高度，该列才可以存水。

​			判断能不能存水后，依据木桶原理，存水量取决于左边最高墙和右边最高墙中最矮的那一面墙，即取出高度最低的墙，其高度减去该列的高度就是该列可以存水的量。

​			动态规划应用于计算每一列的左边最高墙和右边最高墙的高度。

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int len = height.size();
        if(len < 1)
            return ans;
        int maxleft[len];
        int maxright[len];
        maxleft[0] = 0;
        maxright[len-1] = 0;
        for(int i=1; i<len-1; i++)
            maxleft[i] = max(maxleft[i-1],height[i-1]);
        for(int i=len-2; i > 0; i--)
            maxright[i] = max(maxright[i+1],height[i+1]);
        for(int i=1; i<len-1; i++){
            int h = min(maxleft[i],maxright[i]);
            if(h > height[i])
                ans += h - height[i];
        }
        return ans;
    }
};
```

#### 按列计算 + 双指针：

​				优化动态规划的空间复杂度。

#### 栈