## Minimum Sideway Jumps

## 5728. 最少侧跳次数

There is a **3 lane road** of length `n` that consists of `n + 1` **points** labeled from `0` to `n`. A frog **starts** at point `0` in the **second** lane and wants to jump to point `n`. However, there could be obstacles along the way.

You are given an array `obstacles` of length `n + 1` where each `obstacles[i]` (**ranging from 0 to 3**) describes an obstacle on the lane `obstacles[i]` at point `i`. If `obstacles[i] == 0`, there are no obstacles at point `i`. There will be **at most one** obstacle in the 3 lanes at each point.

- For example, if `obstacles[2] == 1`, then there is an obstacle on lane 1 at point 2.

The frog can only travel from point `i` to point `i + 1` on the same lane if there is not an obstacle on the lane at point `i + 1`. To avoid obstacles, the frog can also perform a **side jump** to jump to **another** lane (even if they are not adjacent) at the **same** point if there is no obstacle on the new lane.

- For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.

Return *the **minimum number of side jumps** the frog needs to reach **any lane** at point n starting from lane `2` at point 0.*

**Note:** There will be no obstacles on points `0` and `n`.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex1.png)

```
Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex2.png)

```
Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.
```

**Example 3:**

![img](https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex3.png)

```
Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
```

**Constraints:**

- `obstacles.length == n + 1`
- `1 <= n <= 5 * 10^5`
- `0 <= obstacles[i] <= 3`
- `obstacles[0] == obstacles[n] == 0`

#### 贪心 + 跑道判断：

​		**贪心**：在每一次必须更换跑道的时候，选择可以走最远的那条跑道。

​		**跑道判断**：

- 更换跑道时，如果当前的点和前面一个的点都有障碍，那么更换的跑道不能是当前点的障碍所在的跑道和前一个点的障碍所在的跑道。所以此时我们只有一条跑道可以选择更换。
- 在更换跑道之后，如果有两条跑道可以选择，我们需要判断更换的跑道是不是可以走最远的那条跑道。
  - 如果更换跑道后，首先遇到了没有选择的另一条跑道的障碍，那么我们现在所选择的跑道就是可以走最远的那条跑道。
  - 如果更换跑道后，首先遇到了我们选择的这条跑道的障碍，那么我们选择错误，应该选择另一条跑道，所以我们应该修正跑道，更换新的跑道，但是使用的是之前更换跑道的消耗，不产生新的消耗。

**详见代码注释**：

```c++
class Solution {
public:
    int minSideJumps(vector<int>& ob) {
        // pos：当前跑道，pre：之前的跑道，ch：需要判断是不是可以走最远的那条跑道，lasti：前一个点的障碍所在跑道
        int pos = 2, pre = 2, ch = 0, lasti = 0;
        int ans = 0;
        // 遍历每个点
        for(auto &i : ob){
            // 需要判断是不是可以走最远的那条跑道：当前点有障碍，并且障碍在没有选择的另一条跑道上
            // 更换跑道的选择正确
            if(ch == 1 && i != 0 && i != pos && i != pre)
                // 无需再判断是不是可以走最远的那条跑道
                ch = 0;
            // 当前跑道遇到障碍
            if(i == pos){
                // 需要更换跑道
                if(ch == 0){
                    // 更换次数加一
                    ans++;
                    ch = 1;
                    pre = pos;
                    // 只有一条跑道可以选择，所以无需判断是不是可以走最远的那条跑道
                    if(lasti != 0)
                        ch = 0;
                    // 选择更换到哪一条跑道上
                    pos = pos+1 > 3 ? 1 : pos+1;
                    // 选择的跑道和前一个点的障碍跑道重合了，重新选择跑道
                    if(pos == lasti)
                        pos = pos+1 > 3 ? 1 : pos+1;
                }
                // 需要判断是不是可以走最远的那条跑道：当前点有障碍，并且障碍在我们选择的这条跑道
                // 更换跑道的选择错误
                else{
                    // 无需再判断是不是可以走最远的那条跑道
                    ch = 0;
                    // 修正跑道：更换另一条跑道，使用之前更换的那次消耗
                    pos = pos+1 > 3 ? 1 : pos+1;
                }
            }
            // 记录前一个点的障碍
            lasti = i;
        }
        return  ans;
    }
};
```

