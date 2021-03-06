## Merge Intervals

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

**Example 1:**

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 10^4`

#### 排序 + 双指针：

​			首先将给定的数字区间进行排序。

​			使用双指针，一个指针指向当前答案的最后一个区间元素，另一个指针指向还未进行判断的下一个区间元素。

​			如果当前还存在没有判断的区间元素，继续进行判断：

- 如果当前的区间元素是给定的第一个区间，直接插入答案中。
- 如果当前答案的区间元素最大值小于当前判断的区间元素的最小值，则将当前判断的区间元素直接放入答案中。
- 在上述判断都不满足的情况下，如果当前答案的区间元素最大值小于当前判断的区间元素的最大值，更改当前答案的区间元素最大值为当前判断的区间元素的最大值。
- 因为若当前答案的区间元素最大值大于等于当前判断的区间元素的最大值时，答案不需要进行改变，所以不需要进行任何操作。
- 进入下一个需要判断的区间元素。

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int len = intervals.size();
        int save = 0,next = 0;
        sort(intervals.begin(),intervals.end());
        while(next < len){
            if(next == 0){
                ans.push_back(intervals[next]);
                next++;
                continue;
            }
            if(ans[save][1] < intervals[next][0]){
                ans.push_back(intervals[next]);
                save++;
            }
            else if(ans[save][1] < intervals[next][1]){
                ans[save][1] = intervals[next][1];
            }
            next++;
        }
        return ans;
    }
};
```

