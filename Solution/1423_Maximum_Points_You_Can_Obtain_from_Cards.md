## Maximum Points You Can Obtain from Cards

There are several cards **arranged in a row**, and each card has an associated number of points The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the *maximum score* you can obtain.

**Example 1:**

```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

**Example 2:**

```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```

**Example 3:**

```
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
```

**Example 4:**

```
Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 
```

**Example 5:**

```
Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202
```

**Constraints:**

- `1 <= cardPoints.length <= 10^5`
- `1 <= cardPoints[i] <= 10^4`
- `1 <= k <= cardPoints.length`

#### 滑动窗口：

​		本题中每次行动可以从行的开头或者末尾拿一张卡牌，最终必须正好拿 k 张卡牌。点数就是拿到手中的所有卡牌的点数之和，要求返回可以获得的最大点数。

​		其实就是从数组的开头取 h 个元素，从数组的结尾取 t 个元素，使得 h + t == k，求得所有 h 和 t 的不同取值中元素之和最大的情况。我们把数组的头尾相连起来，其实就是在开头的第一个元素到第 k 个元素加上结尾最后一个元素到最后第 k 个元素这个区间中，找出长度为 k 的连续子数组的各元素之和的最大情况。

​		有了连续子数组，就应该想到可以使用滑动窗口，由于长度固定为 k，所以有一个元素添加就必定有一个元素去除。我们首先计算开头 k 个元素的元素之和，然后开始讨论结尾部分，每次按顺序添加结尾的元素，就应该对应地去除开头的元素，并且一直更新最大值的情况。

​		最后结尾的 k 个元素都讨论完成，返回最大值。

```c++
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), cur = 0;
        for(int i=0; i<k; i++)
            cur += cardPoints[i];
        int ans = cur;
        for(int i=0; i<k; i++){
            cur = cur - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
```

