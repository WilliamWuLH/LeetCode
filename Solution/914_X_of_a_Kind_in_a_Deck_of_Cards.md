## X of a Kind in a Deck of Cards

In a deck of cards, each card has an integer written on it.

Return `true` if and only if you can choose `X >= 2` such that it is possible to split the entire deck into 1 or more groups of cards, where:

- Each group has exactly `X` cards.
- All the cards in each group have the same integer.

**Example 1:**

```
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
```

**Example 2:**

```
Input: deck = [1,1,1,2,2,2,3,3]
Output: false´
Explanation: No possible partition.
```

**Example 3:**

```
Input: deck = [1]
Output: false
Explanation: No possible partition.
```

**Example 4:**

```
Input: deck = [1,1]
Output: true
Explanation: Possible partition [1,1].
```

**Example 5:**

```
Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].
```

**Constraints:**

- `1 <= deck.length <= 10^4`
- `0 <= deck[i] < 10^4`

#### 计数 + 最大公约数：

​			统计各个数字的个数，再求出所有数字的个数的最大公约数，判断是否大于等于 2。

```c++
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> count;
        int len = deck.size();
        for(int i=0; i<len; i++)
            count[ deck[i] ]++;
        int temp = 0;
        map<int,int>::iterator mit;
        for(mit=count.begin(); mit!=count.end(); mit++){
            temp = gcd(mit->second, temp);
        }
        return temp >= 2;
    }
    int gcd(int a, int b){
        return !a ? b : gcd(b%a, a);
    }
};
```

