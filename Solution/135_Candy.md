## Candy

There are *N* children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

**Example 1:**

```
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

**Example 2:**

```
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
```

#### 规则分解 + 两次遍历：

​		Children with a higher rating get more candies than their neighbors. 这条规则可以分解为两条规则：

左规则 left：当 ratings[i-1] < ratings[i] 时，第 i 个学生的糖果数目应该比第 i-1 个学生的糖果数目多。

右规则 right：当 ratings[i] > ratings[i+1] 时，第 i 个学生的糖果数目应该比第 i+1 个学生的糖果数目多。

我们遍历 ratings 数组两次，处理出每一个学生分别满足左规则或右规则时，最少需要被分得的糖果数量。每个人最终分得的糖果数量即为这两个数量的最大值。

**为什么最终分得的糖果数量是这两个数量（left & right）的最大值？**

首先，我们仅讨论第 i 个学生：

第 i 个学生最终分得的糖果数量应该同时满足左规则和右规则，这样才满足题目所要求的条件，第 i 个学生满足左规则的最少糖果数目为 left[i]，满足右规则的最少糖果数目为 right[i]，这两个数目都是对应规则的最少数目，所以只能多但是不能少，所以要使得第 i 个学生同时满足左规则和右规则，最优的糖果数目也就是这两个数量（left & right）的最大值。

把第 i 个学生最终分得的糖果数量讨论扩展到全部学生，同理，全部学生最终分得的糖果数量也是这两个数量（left & right）的最大值。

在进行代码实现时，执行右规则时不一定要开一个 right[] 数组，可以仅用一个 right 变量迭代更新当前学生的右规则 right 糖果数目。

```c++
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int left[n];
        for(int i=0; i<n; i++){
            if(i > 0 && ratings[i-1] < ratings[i])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
        }
        int ans = 0, right = 1;
        for(int i=n-1; i>=0; i--){
            if(i < n-1 && ratings[i] > ratings[i+1])
                right++;
            else
                right = 1;
            ans += max(left[i], right);
        }
        return ans;
    }
};
```

