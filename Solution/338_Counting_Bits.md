## Counting Bits

Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.

**Example 1:**

```
Input: 2
Output: [0,1,1]
```

**Example 2:**

```
Input: 5
Output: [0,1,1,2,1,2]
```

**Follow up:**

- It is very easy to come up with a solution with run time **O(n\*sizeof(integer))**. But can you do it in linear time **O(n)** /possibly in a single pass?
- Space complexity should be **O(n)**.
- Can you do it like a boss? Do it without using any builtin function like **__builtin_popcount** in c++ or in any other language.

#### 通过前面算后面：

1. 如果数字是 0，则它的二进制数的 1 的数目为 0。

2. 如果此时的数字是奇数，它的二进制数的 1 的数目等于它的前一个数（偶数）的二进制数的 1 的数目加 1。

   原因是：此时的奇数等于它的前一个数（偶数）的二进制数第 0 位的 0 变为 1。

3. 如果此时的数字是偶数且不为 0，它的二进制数的 1 的数目等于它除以 2（右移一位）之后的数的二进制数的 1 的数目。

   原因是：此时的偶数的第 0 位是 0，所以除以 2（右移一位）之后结果不变，计算之后该数的二进制数的 1 的数目之前已经计算过了，并且结果和此时的偶数相同。

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0; i<=num; i++){
            if(i == 0)
                ans.push_back(0);
            else if(i%2)
                ans.push_back(ans[i-1]+1);
            else if(i%2 == 0)
                ans.push_back(ans[i>>1]);
        }
        return ans;
    }
};
```

