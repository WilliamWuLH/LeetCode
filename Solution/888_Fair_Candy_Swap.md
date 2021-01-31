## Fair Candy Swap

Alice and Bob have candy bars of different sizes: `A[i]` is the size of the `i`-th bar of candy that Alice has, and `B[j]` is the size of the `j`-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy. (*The total amount of candy a person has is the sum of the sizes of candy bars they have.*)

Return an integer array `ans` where `ans[0]` is the size of the candy bar that Alice must exchange, and `ans[1]` is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them. It is guaranteed an answer exists.

**Example 1:**

```
Input: A = [1,1], B = [2,2]
Output: [1,2]
```

**Example 2:**

```
Input: A = [1,2], B = [2,3]
Output: [1,2]
```

**Example 3:**

```
Input: A = [2], B = [1,3]
Output: [2,3]
```

**Example 4:**

```
Input: A = [1,2,5], B = [2,4]
Output: [5,4]
```

**Note:**

- `1 <= A.length <= 10000`
- `1 <= B.length <= 10000`
- `1 <= A[i] <= 100000`
- `1 <= B[i] <= 100000`
- It is guaranteed that Alice and Bob have different total amounts of candy.
- It is guaranteed there exists an answer.

#### 哈希表 + 数学公式：

​		记爱丽丝的糖果棒的总大小为 sumA，鲍勃的糖果棒的总大小为 sumB。设答案为 \{ x , y \}，即爱丽丝的大小为 x 的糖果棒与鲍勃的大小为 y 的糖果棒交换，则有如下等式：sumA − x + y = sumB + x − y。

​		化简，得：y = x - ( sumA − sumB ) / 2，即对于 A 中的任意一个数 x，只要 B 中存在一个数 y，满足 y = x - ( sumA − sumB ) / 2，那么 \{ x , y \} 即为一组可行解。

​		为了快速查询 B 中是否存在某个数，我们可以先将 B 中的数字存入哈希表中。然后遍历 A 序列中的数 x，在哈希表中查询是否有对应的 y。

**参考：[力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/)**

**相关阅读：**

- [C++的STL中accumulate的用法](https://blog.csdn.net/u011499425/article/details/52756242)
- [accumulate](http://www.cplusplus.com/reference/numeric/accumulate/)
- [unordered_set](http://www.cplusplus.com/reference/unordered_set/unordered_set/)

```c++
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans(2, 0);
        int asum = accumulate(A.begin(), A.end(), 0);
        int bsum = accumulate(B.begin(), B.end(), 0);
        int temp = (asum - bsum) >> 1;
        unordered_set<int> theB(B.begin(), B.end());
        for(auto &i : A){
            int cur = i - temp;
            if(theB.count(cur)){
                ans[0] = i;
                ans[1] = cur;
                break;
            }
        }
        return ans;
    }
};
```

