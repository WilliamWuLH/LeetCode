## Boats to Save People

The `i`-th person has weight `people[i]`, and each boat can carry a maximum weight of `limit`.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most `limit`.

Return the minimum number of boats to carry every given person. (It is guaranteed each person can be carried by a boat.)

**Example 1:**

```
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
```

**Example 2:**

```
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
```

**Example 3:**

```
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
```

**Note**:

- `1 <= people.length <= 50000`
- `1 <= people[i] <= limit <= 30000`

#### 贪心：双指针

**思路**

​		如果最重的人可以与最轻的人共用一艘船，那么就这样安排。否则，最重的人无法与任何人配对，那么他们将自己独自乘一艘船。

​		这么做的原因是，如果最轻的人可以与任何人配对，那么他们也可以与最重的人配对。

​		最重的走的时候，如果能带，一定要带个人走，这才是合理的，否则，例如【1,3】，limit = 4，这种，3先自己坐船走，1只能再乘一条船。显然不合理。 那最终的走的时候，带谁走呢，显然是最轻的（当然他也可能能够次轻的同乘一条船），反证下，如果因为它带了最轻的，导致次轻的无法跟其他人同船，那么次轻的也一定无法跟最重的乘船。如果次轻的可以跟其他人同船，则反正同船了，跟谁效果都一样。所以 不会因为最重的选择了最轻的同船，导致后面的配对结果更坏。 

**算法**

​		令 people[i] 指向当前最轻的人，而 people[j] 指向最重的那位。

​		然后，如上所述，如果最重的人可以与最轻的人共用一条船（即 people[j] + people[i] <= limit），那么就这样做；否则，最重的人自己独自坐在船上。

**参考：[力扣 (LeetCode)](https://leetcode-cn.com/u/leetcode/)**

```c++
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int l = 0, r = people.size()-1;
        sort(people.begin(), people.end());
        while(l <= r){
            ans++;
            if(people[l] + people[r] <= limit)
                l++;
            r--;
        }
        return ans;
    }
};
```

