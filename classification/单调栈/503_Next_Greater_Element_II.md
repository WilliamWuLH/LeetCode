## Next Greater Element II

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

**Example 1:**

```
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; The number 2 can't find next greater number; The second 1's next greater number needs to search circularly, which is also 2.
```

**Note:** The length of given array won't exceed 10000.

#### 单调栈 + 循环数组：

​		可以使用单调栈解决本题。单调栈中保存的是下标，从栈底到栈顶的下标在数组 nums 中对应的值是单调不升的。

​		每次我们移动到数组中的一个新的位置 i，我们就将当前单调栈中所有对应值小于 nums\[ i \] 的下标弹出单调栈，这些值的下一个更大元素即为 nums \[ i \]（证明很简单：如果有更靠前的更大元素，那么这些位置将被提前弹出栈）。随后我们将位置 i 入栈。

​		但是注意到只遍历一次序列是不够的，例如序列 \[ 2 , 3 , 1 \]，最后单调栈中将剩余 \[ 3 , 1 \]，其中元素 \[ 1 \] 的下一个更大元素还是不知道的。

​		一个朴素的思想是，我们可以把这个循环数组「拉直」，即复制该序列的前 n−1 个元素拼接在原序列的后面。这样我们就可以将这个新序列当作普通序列，用上文的方法来处理。

​		而在本题中，我们不需要显性地将该循环数组「拉直」，而只需要在处理时对下标取模即可。

参考：[力扣官方题解](https://leetcode-cn.com/problems/next-greater-element-ii/solution/xia-yi-ge-geng-da-yuan-su-ii-by-leetcode-bwam/)

```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for(int i = 0; i < 2 * n - 1; i++){
            while( !s.empty() && nums[ s.top() ] < nums[ i % n ]){
                ans[ s.top() ] = nums[ i % n ];
                s.pop();
            }
            s.push( i % n );
        }
        return ans;
    }
};
```

