## Assign Cookies

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child `i` has a greed factor `g[i]`, which is the minimum size of a cookie that the child will be content with; and each cookie `j` has a size `s[j]`. If `s[j] >= g[i]`, we can assign the cookie `j` to the child `i`, and the child `i` will be content. Your goal is to maximize the number of your content children and output the maximum number.

**Example 1:**

```
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
```

**Example 2:**

```
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
```

**Constraints:**

- `1 <= g.length <= 3 * 10^4`
- `0 <= s.length <= 3 * 10^4`
- `1 <= g[i], s[j] <= 2^31 - 1`

#### 排序 + 贪心选择：

​		首先，将孩子的胃口值 g[] 数组和每块饼干的尺寸值 s[] 数组按照从小到大的顺序进行排序。

​		接着，当还有孩子没有分到饼干（ gi != glen ）并且家长还有饼干（ si != slen ）时，拿出此时剩余饼干的最小尺寸，判断这个最小尺寸的饼干是否可以满足此时剩余的孩子中胃口值最小的孩子，即是否满足 g[gi] <= s[si]。如果满足，则此时有一个孩子满足了（gi++），有一块饼干被吃掉了（si++），并且满足一个孩子（ans++）。如果不满足，说明此时最小尺寸的饼干还无法满足最小胃口值的孩子，需要更大尺寸的饼干，所以当前的饼干没有用了，找下一块最小尺寸的饼干了（si++）。

​		当孩子都分到了饼干（ si == slen ）或者没有饼干可以分发（ gi == glen ）时结束循环，返回答案 ans。

```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int glen = g.size(), slen = s.size(), gi = 0, si = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(gi != glen && si != slen){
            if(g[gi] <= s[si]){
                ans++;
                gi++;
                si++;
            }
            else
                si++;
        }
        return ans;
    }
};
```

