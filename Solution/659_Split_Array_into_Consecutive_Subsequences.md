## Split Array into Consecutive Subsequences

Given an array `nums` sorted in ascending order, return `true` if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.

**Example 1:**

```
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
```

**Example 2:**

```
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
```

**Example 3:**

```
Input: [1,2,3,4,4,5]
Output: False
```

**Constraints:**

- `1 <= nums.length <= 10000`

#### 贪心：

使用两个哈希表，第一个哈希表存储数组中的每个数字的剩余次数，第二个哈希表存储数组中的每个数字作为结尾的子序列的数量。

初始时，每个数字的剩余次数即为每个数字在数组中出现的次数，因此遍历数组，初始化第一个哈希表。

在初始化第一个哈希表之后，遍历数组，更新两个哈希表。只有当一个数字的剩余次数大于 0 时，才需要考虑这个数字是否属于某个子序列。假设当前元素是 x，进行如下操作。

- 首先判断是否存在以 x−1 结尾的子序列，即根据第二个哈希表判断 x−1 作为结尾的子序列的数量是否大于 0，如果大于 0，则将元素 x 加入该子序列中。由于 x 被使用了一次，因此需要在第一个哈希表中将 x 的剩余次数减 1。又由于该子序列的最后一个数字从 x−1 变成了 x，因此需要在第二个哈希表中将 x−1 作为结尾的子序列的数量减 1，以及将 x 作为结尾的子序列的数量加 1。
- 否则，x 为一个子序列的第一个数，为了得到长度至少为 3 的子序列，x+1 和 x+2 必须在子序列中，因此需要判断在第一个哈希表中 x+1 和 x+2 的剩余次数是否都大于 0。
  - 当 x+1 和 x+2 的剩余次数都大于 0 时，可以新建一个长度为 3 的子序列 x,x+1,x+2。由于这三个数都被使用了一次，因此需要在第一个哈希表中将这三个数的剩余次数分别减 1。又由于该子序列的最后一个数字是 x+2，因此需要在第二个哈希表中将 x+2 作为结尾的子序列的数量加 1。
  - 否则，无法得到长度为 3 的子序列 x,x+1,x+2，因此无法完成分割，返回 false。

如果整个数组遍历结束时，没有遇到无法完成分割的情况，则可以完成分割，返回 true。

参考：力扣官方题解

```c++
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> end;
        for(auto &i : nums)
            count[i]++;
        for(auto &i : nums){
            if(count[i] > 0){
                if(end[i-1] > 0){
                    count[i]--;
                    end[i-1]--;
                    end[i] += 1;
                }
                else if(count[i+1] > 0 && count[i+2] > 0){
                    count[i]--;
                    count[i+1]--;
                    count[i+2]--;
                    end[i+2]++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
```

