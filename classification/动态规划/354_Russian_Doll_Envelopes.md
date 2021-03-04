## Russian Doll Envelopes

You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

Return *the maximum number of envelopes can you Russian doll (i.e., put one inside the other)*.

**Note:** You cannot rotate an envelope.

**Example 1:**

```
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

**Example 2:**

```
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

**Constraints:**

- `1 <= envelopes.length <= 5000`
- `envelopes[i].length == 2`
- `1 <= wi, hi <= 10^4`

#### 动态规划：最长递增子序列

​		给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

​		要想使一个信封 (w1, h1) 可以放入另一个信封 (w2, h2)，就要满足 w1 < w2 \&\& h1 < h2。题目要求计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面），其实就是求给定的信封数组中的最长递增子序列。

​		最长递增子序列问题是一个动态规划的问题，首先我们需要对信封数组进行排序，将信封按照从小到大的顺序进行排列，这样方便我们后续进行动态规划。

​		在进行动态规划的时候，我们判断当前信封是否可以装下之前的某一个小信封，如果可以，判断取出当前信封的套娃数目和之前小信封的套娃数目加一的最大值。在这期间可以实时更新整个信封数组的套娃最大值。

```c++
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), ans = n > 0 ? 1 : 0;
        sort(envelopes.begin(), envelopes.end(), [&](const auto& a, const auto& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

#### 方法二：基于二分查找的动态规划

[力扣官方题解](https://leetcode-cn.com/problems/russian-doll-envelopes/solution/e-luo-si-tao-wa-xin-feng-wen-ti-by-leetc-wj68/)