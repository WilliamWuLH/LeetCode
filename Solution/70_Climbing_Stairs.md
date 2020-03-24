## Climbing Stairs

#### 动态规划：

​			记录保存爬到每一层楼梯的路径数目，当层数大于等于 2 时，该层的路径数目等于前一层的路径数目加上前两层的路径数目。

```c++
class Solution {
public:
    int climbStairs(int n) {
        int path[n+1];
        path[0] = 1;
        path[1] = 1;
        for(int i=2; i<=n; i++){
            path[i] = path[i-1] + path[i-2];
        }
        return path[n];
    }
};
```

