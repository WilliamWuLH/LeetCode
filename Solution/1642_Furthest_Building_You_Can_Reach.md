## Furthest Building You Can Reach

You are given an integer array `heights` representing the heights of buildings, some `bricks`, and some `ladders`.

You start your journey from building `0` and move to the next building by possibly using bricks or ladders.

While moving from building `i` to building `i+1` (**0-indexed**),

- If the current building's height is **greater than or equal** to the next building's height, you do **not** need a ladder or bricks.
- If the current building's height is **less than** the next building's height, you can either use **one ladder** or `(h[i+1] - h[i])` **bricks**.

*Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.*

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/27/q4.gif)

```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

**Example 2:**

```
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

**Example 3:**

```
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

**Constraints:**

- `1 <= heights.length <= 10^5`
- `1 <= heights[i] <= 10^6`
- `0 <= bricks <= 10^9`
- `0 <= ladders <= heights.length`

#### 优先队列（最小堆） + 贪心：

​		在移动的过程中，我们会需要若干次需要使用砖块或者梯子的情况。假设当前我们需要移动到下一建筑物，但必须使用 1 架梯子或者 Δh 个砖块，那么我们如何抉择是使用梯子还是砖块呢？

​		我们可以用贪心的思路来想这个问题。「梯子」相当于一次性的无限量砖块，那么我们一定是把梯子用在刀刃上。也就是说，如果我们有 l 架梯子，那么我们会在 Δh 最大的那 l 次使用梯子，而在剩余的情况下使用砖块。

​		这样一来，我们就可以得到正确的算法了：我们使用优先队列实时维护不超过 l 个最大的 Δh，这些就是使用梯子的地方。对于剩余的 Δh，我们需要使用砖块，因此需要对它们进行累加，如果某一时刻这个累加值超过了砖块的数目 b，那么我们就再也无法移动了。

参考：

- [priority_queue](http://www.cplusplus.com/reference/queue/priority_queue/)
- [优先队列 + 贪心](https://leetcode-cn.com/problems/furthest-building-you-can-reach/solution/ke-yi-dao-da-de-zui-yuan-jian-zhu-by-zerotrac2/)

```c++
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> q;
        int n = heights.size(), ans = 0;
        for(int i=1; i<n; i++){
            if(heights[i] - heights[i-1] > 0){
                q.push(heights[i]-heights[i-1]);
                while(q.size() > ladders){
                    int t = q.top();
                    q.pop();
                    if(bricks < t)
                        return ans;
                    bricks -= t;
                }
            }
            ans = i;
        }
        return ans;
    }
};
```

