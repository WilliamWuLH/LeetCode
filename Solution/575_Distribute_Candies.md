## Distribute Candies

Alice has `n` candies, where the `i^th` candy is of type `candyType[i]`. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat `n / 2` of the candies she has (`n` is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array `candyType` of length `n`, return *the **maximum** number of different types of candies she can eat if she only eats* `n / 2` *of them*.

**Example 1:**

```
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
```

**Example 2:**

```
Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
```

**Example 3:**

```
Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.
```

**Constraints:**

- `n == candyType.length`
- `2 <= n <= 10^4`
- `n` is even.
- `-10^5 <= candyType[i] <= 10^5`

#### 通过 set 统计糖果的种类数目：

​		通过集合 set 对所有糖果中的种类数目进行统计。

​		最后在返回时需要进行进一步判断，判断是所有糖果进行平分之后的数量多还是糖果的种类数目多。

```c++
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> type;
        for(auto &i : candyType)
            type.emplace(i);
        return min(candyType.size() / 2, type.size());
    }
};
```

#### 通过数据范围对代码进行优化：

​		已知糖果种类的数据范围，可以进行空间上的优化。

```c++
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int count[200001];
        memset(count, 0, sizeof(int)*200001);
        for(auto &i : candyType)
            count[i + 100000]++;
        int sum = 0;
        for(int i=0; i<200001; i++)
            if(count[i] != 0)
                sum++;
        int n = candyType.size();
        return min(n / 2, sum);
    }
};
```

