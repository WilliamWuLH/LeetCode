## Remove K Digits

Given a non-negative integer *num* represented as a string, remove *k* digits from the number so that the new number is the smallest possible.

**Note:**

- The length of *num* is less than 10002 and will be ≥ *k*.
- The given *num* does not contain any leading zero.

**Example 1:**

```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

**Example 2:**

```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

**Example 3:**

```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

#### 单调栈 + 贪心：

删除一个数字的贪心策略：

​		给定一个长度为 n 的数字序列 D0,D1,D2,D3 …… Dn-1，从左往右找到第一个位置 i （i > 0）使得 Di < Di-1，并删去 Di-1，如果不存在，说明整个数字序列单调不降，删去最后一个数字即可。

​		可以每次对数字序列执行一次这个策略，删去一个字符之后，剩下的长度为 n-1 的数字序列形成子问题，继续使用相同的策略，直到删除 k 次。

​		该过程可以通过单调栈模拟。

​		单调栈中的元素代表截止到当前位置，删除不超过 k 次个数字后，所能得到的最小整数。根据之前的讨论：在使用 k 个删除次数之前，栈中的序列从栈底到栈顶单调不降。

​		详见代码。

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        vector<char> s;
        for(auto &i : num){
            while(k && s.size() > 0 && s.back() > i){
                s.pop_back();
                k--;
            }
            s.push_back(i);
        }
        while(k){
            s.pop_back();
            k--;
        }
        bool flag = true;
        for(auto &i : s){
            if(i == '0' && flag)
                continue;
            flag = false;
            ans += i;
        }
        return ans == "" ? "0" : ans;
    }
};
```

