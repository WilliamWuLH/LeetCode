## Largest Rectangle in Histogram

 Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram. 

 Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`. 

 The largest rectangle is shown in the shaded area, which has area = `10` unit. 

**Example:**

```
Input: [2,1,5,6,2,3]
Output: 10
```

#### 单调栈：

​		单调栈的作用：找出数组中每个元素的左边第一个比它小（大）的数和右边第一个比它小（大）的数。

​		单调栈顾名思义，就是按照单调递增或者单调递减的规律来组织栈。

​		怎么使用（组织）单调栈？

​		遍历数组中的每一个元素，当此时栈为空或者栈顶元素小于（大于）或者等于当前数组元素时，将当前数组元素加入栈中，并讨论下一个数组元素。

​		当此时数组元素大于（小于）栈顶元素时，取出当前的栈顶元素并进行操作讨论，然后再次判断现在的数组元素是否大于（小于）当前栈顶元素（已经弹出了之前的栈顶元素）。直到满足此时单调栈为空或者数组元素小于（大于）或者等于当前栈顶元素，将数组元素加入到栈中。

​		针对于这道题：

​		怎么解：对于每一条柱子，讨论以该柱子的高度作为矩形高度，可以形成的最大的矩形面积，最后得到所有柱子中可形成的最大矩形面积。

​		要得到哪些量：因为要求每一条柱子可以形成的最大矩形，需要知道矩形的高度（已知）和宽度。

​		定义：柱子 H 左边第一个高度比它小的柱子的索引 left，柱子 H 右边第一个高度比它小的柱子的索引 right。

​		所以该柱子 H 可形成最大矩形的宽度为：right - left - 1

​		使用单调栈：按照柱子高度单调递增的规则组织单调栈。当此时栈为空或者柱子高度大于等于栈顶元素时，把该柱子索引加入到栈中；当此时柱子高度小于栈顶元素时，取出栈顶元素（柱子）来形成它的最大矩形面积。通过单调栈可以找出每一条柱子的左边第一个高度比它小的柱子的索引 left 和右边第一个高度比它小的柱子的索引 right。（我讲不清楚了，详见代码）

​		记住算完一个柱子的最大矩形面积后要更新此时的答案。

​		重点难点：第一个柱子和最后一个柱子。

​		当单调栈为空时，说明此时的柱子是有史以来最小的，只好把第一个柱子作为它的左边界（要算入最大矩形的），所以此时的柱子的 left 应该是 -1（因为是开区间，所以是 -1 而不是 0）。

​		当讨论到最后一个柱子之后单调栈还有元素时，说明此时单调栈中的元素（柱子）仍未找到它们的 right，只好把最后一个柱子作为右边界（要算入最大矩形的），所以此时的 right 应该是 heights.size()。

​		这里有个小技巧：在 heights 数组的最后再添加一个 0（柱子高度为 0）。

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int len = heights.size();
        int ans = 0;
        stack<int> s;
        for(int i=0; i<len; i++){
            while(!s.empty() && heights[ s.top() ] > heights[i]){
                int h = heights[ s.top() ];
                s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                ans = max(ans, h * (right - left - 1));
            }
            s.push(i);
        }
        return ans;
    }
};
```

