## Plus One

Given a **non-empty** array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
```

**Example 2:**

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
```

**Example 3:**

```
Input: digits = [0]
Output: [1]
```

**Constraints:**

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`

#### 是否进位了：

​		判断加 1 之后是否会进位，进位了就继续计算，不进位就返回。

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i>=0; i--){
            digits[i]++;
            digits[i] %= 10;
            if(digits[i] != 0)
                return digits;
        }
        vector<int> ans = digits;
        ans.insert(ans.begin(), 1);
        return ans;
    }
};
```

