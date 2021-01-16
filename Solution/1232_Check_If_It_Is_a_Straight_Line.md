## Check If It Is a Straight Line

You are given an array `coordinates`, `coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these points make a straight line in the XY plane.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg)

```
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg)

```
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

**Constraints:**

- `2 <= coordinates.length <= 1000`
- `coordinates[i].length == 2`
- `-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4`
- `coordinates` contains no duplicate point.

#### 判断坐标系内各个点是否在一条线上：

​		这种题的第一反应就是求斜率，但是在编程实现中，求斜率并不是最好的方法，原因如下：

1. 在计算机中除法运算不是精确的，所以会有误差，有可能真实情况在同一条直线上的点被“误判”为不在同一直线上。
2. 单次除法运算的计算量比单次乘法运算的计算量大，能进行乘法运算的就不要做除法运算。
3. 在本题中，求斜率做除法运算还需要考虑分母不能为 0 的情况。

综上所述，具体代码实现如下：

```c++
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int a = coordinates[0][0] - coordinates[1][0], b = coordinates[0][1] - coordinates[1][1];
        for(int i=2; i<n; i++)
            if(a * (coordinates[0][1] - coordinates[i][1]) != b * (coordinates[0][0] - coordinates[i][0]))
                return false;
        return true;
    }
};
```

