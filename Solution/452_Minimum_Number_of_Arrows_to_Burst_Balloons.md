## Minimum Number of Arrows to Burst Balloons

There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with `xstart` and `xend` bursts by an arrow shot at `x` if `xstart ≤ x ≤ xend`. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array `points` where `points[i] = [xstart, xend]`, return *the minimum number of arrows that must be shot to burst all balloons*.

**Example 1:**

```
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
```

**Example 2:**

```
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
```

**Example 3:**

```
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
```

**Example 4:**

```
Input: points = [[1,2]]
Output: 1
```

**Example 5:**

```
Input: points = [[2,3],[2,3]]
Output: 1
```

**Constraints:**

- `0 <= points.length <= 10^4`
- `points[i].length == 2`
- `-2^31 <= xstart < xend <= 2^31 - 1`

#### 按右端升序排序 + 贪心

为什么要排序：分析题意可知，这道题是区间贪心问题，既然是区间，就需要按序讨论各个区间。

为什么**不按左端**升序排序：

​		举个例子：\[0,8\]，\[1,4\]，\[5,8\]。

​		\[1,4\] 和 \[5,8\] 都在 \[0,8\] 中，但是 \[1,4\] 和 \[5,8\] 不互相覆盖，且判断不出。

为什么**按右端**升序排序：

​		按照每个区间的右端进行排序，然后按照区间左端进行贪心计算。

​		如果区间左端在当前区间右端 cur 的左边，则说明这两个区间一定有重叠部分。

​		如果区间左端在当前区间右端 cur 的右部，则说明这两个区间一定没有重叠的部分。

​		此时的贪心就贪心在当前区间右端 cur，当前区间右端 cur 表示的是可以互相覆盖的最右边。

```c++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        int ans = 1;
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b){
            if(a[1] > b[1])
                return false;
            return true;
        });
        int cur = points[0][1];
        for(auto &i : points){
            if(i[0] > cur){
                ans++;
                cur = i[1];
            }
        }
        return ans;
    }
};
```

