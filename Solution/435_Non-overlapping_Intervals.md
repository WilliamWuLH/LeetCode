## Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

**Example 1:**

```
Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
```

**Example 2:**

```
Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
```

**Example 3:**

```
Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

**Note:**

1. You may assume the interval's end point is always bigger than its start point.
2. Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

#### 动态规划：本质上是一个「最长上升子序列」问题

​		首先，对所有区间进行排序，按照区间的左值（起点）的大小进行排序。

​		然后，按照最长上升子序列的思想进行动态规划：

- 讨论此时的第 i 个区间，记录此时前 i 个区间中符合条件（无重叠）的区间个数为 f[i]
- 遍历第 i 个区间之前的所有区间，设进行讨论的区间为第 j 个区间（j < i）
  - 如果此时第 j 个区间和第 i 个区间符合条件（无重叠），即第 j 个区间的右值（终点）小于等于第 i 个区间的左值（起点），则更新此时的 f[i]：f[i] = max ( f[j] + 1, f[i] )
  - 如果此时第 j 个区间和第 i 个区间不符合条件，则不处理，讨论下一个
- 最后一个区间（第 n-1 个区间）的记录符合条件区间个数值（ f[n-1] ）为最大的区间个数。
- 所以答案为 n - f[n-1]

```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2)
            return 0;
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        vector<int> f(n, 1);
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++)
                if(intervals[j][1] <= intervals[i][0])
                    f[i] = max(f[j]+1, f[i]);
        return n-f[n-1];
    }
};
```

#### 贪心算法：

​		首先，对所有区间进行排序，按照区间的右值（终点）的大小进行排序。

​		接着遍历此时的区间数组，开始贪心：

- 如果此时所讨论的区间和前面已经符合条件的区间都不重叠，即 intervals\[i\]\[0\] >= cur_end，说明此时该区间也属于符合条件的区间，所以更新 cur_end 为 intervals\[i\]\[1\]。
- 如果此时所讨论的区间和前面已经符合条件的区间重叠，即 intervals\[i\]\[0\] < cur_end，则应该被剔除。

最终剔除的区间个数就是答案。

**为什么可以这样做？**

因为这就是贪心的思想！

我们按照区间的右值（终点）的大小进行排序，所以在遍历区间数组并添加符合条件（无重叠）的区间时就是希望此时符合条件的区间所覆盖的区域更小，从而使得有更多的区间可以被添加，最终使得更少的区间被剔除，所以通过贪心思想可以找到需要移除区间的最小数量。

```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2)
            return 0;
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int ans = 0;
        int cur_end = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < cur_end)
                ans++;
            else
                cur_end = intervals[i][1];
        }
        return ans;
    }
};
```

