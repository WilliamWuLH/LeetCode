## Rabbits in Forest

In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those `answers` are placed in an array.

Return the minimum number of rabbits that could be in the forest.

```
Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
```

**Note:**

1. `answers` will have length at most `1000`.
2. Each `answers[i]` will be an integer in the range `[0, 999]`.

#### 哈希表 + 贪心：

​		首先兔子不会骗人，所以兔子说有 i 只一样颜色的兔子，其实就是总共可能会有 i+1 只兔子（算上它自己），哈希表就是记录这个的，每次有一只兔子说一个数字 i，哈希表记录 hash[i+1]++，表示这个数字的兔子又多一只。

​		其次，不是所有的兔子都会出来说话（要不然直接算数组长度就可以了），所以，需要对哈希表进行判断，如果说有 0 只兔子和它一样，那么它独一无二，直接兔子数 ans 加一。

​		如果有 n 只兔子说过有 i 只兔子和它颜色一样，这个时候就需要进行贪心了。

​		我们贪心地认为 n 中有 i 只兔子是符合的（n > i 的情况），所以我们需要计算 n / i 的值，也就是需要把 n 分为几组不同的颜色。最后颜色组数 z 乘以 i 就是说过数字 i 的兔子的总数。

​		最后相加得到答案。

```c++
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> hash;
        for(auto &i : answers)
            hash[i+1]++;
        unordered_map<int, int>::iterator it = hash.begin();
        for(; it != hash.end(); it++){
            if(it->first != 0)
                ans += (it->second / it->first + (it->second % it->first != 0)) * it->first;
            else
                ans += 1;
        }
        return ans;
    }
};
```

