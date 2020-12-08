## Split Array into Fibonacci Sequence

Given a string `S` of digits, such as `S = "123456579"`, we can split it into a *Fibonacci-like sequence* `[123, 456, 579].`

Formally, a Fibonacci-like sequence is a list `F` of non-negative integers such that:

- `0 <= F[i] <= 2^31 - 1`, (that is, each integer fits a 32-bit signed integer type);
- `F.length >= 3`;
- and` F[i] + F[i+1] = F[i+2] `for all `0 <= i < F.length - 2`.

Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from `S`, or return `[]` if it cannot be done.

**Example 1:**

```
Input: "123456579"
Output: [123,456,579]
```

**Example 2:**

```
Input: "11235813"
Output: [1,1,2,3,5,8,13]
```

**Example 3:**

```
Input: "112358130"
Output: []
Explanation: The task is impossible.
```

**Example 4:**

```
Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
```

**Example 5:**

```
Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
```

**Note:**

1. `1 <= S.length <= 200`
2. `S` contains only digits.

#### 回溯法 backtrack + 剪枝：

​		给定一个数字字符串，将它分成斐波那契式的序列。首先想到的方法就是回溯法，可以枚举出整个状态空间，通过剪枝策略来缩小状态空间，提高性能。

​		我们需要记录遍历到数字字符串的哪个位置，每次从当前位置取出可能的数，这里存在多个剪枝策略：

1. **取出的数不符合题目的要求**，例如取出的数有前导 0（0123），或者取出的数超过了 32 位有符号整数类型范围，在实现判断取出的数是否符合要求时，我们可以在把字符串转化为 int 型变量的时候就完成判断。

2. 数字字符串剩下的数比现在取出的数还小，无法形成斐波那契式，此时可以进行剪枝。

3. 数字字符串还可以取出数字，但是当前斐波那契式的序列的最后一个数和倒数第二个数相加已经超过 int 范围，此时需要剪枝。

4. 当前取出的数已经太大，超过斐波那契式的序列后两个数的和，需要剪枝。

   ​	详见代码，有完整注释：

```c++
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if(S.empty())
            return ans;
        backtrack(S, 0, ans, 0);
        return ans;
    }
    bool backtrack(string S, int sindex, vector<int> &ans, int ansindex){
        int slen = S.length();
        //数字字符串遍历完了，并且可以分成斐波那契式的序列，结束
        if(sindex == slen && ansindex >= 3)
            return true;
        //讨论当前可能取出的每一个数
        for(int l=1; l<=slen-sindex && l<11; l++){
            int cur = my_stoi(S.substr(sindex, l));
            //剪枝：取出的数不符合（有前导0或者超过int范围）
            if(cur == -1)
                return false;
            //取出的序列少于两个数，把取出的数直接添加入序列
            if(ansindex < 2){
                //剪枝：数字字符串剩下的数比现在取出的数还小，无法形成斐波那契式
                if(l > slen-l-sindex)
                    return false;
                //添加入序列
                ans.push_back(cur);
                bool cur_stat = backtrack(S, sindex+l, ans, ansindex+1);
                if(cur_stat)
                    return true;
                ans.pop_back();
            }
            //取出的序列中数的个数超过两个，需要判断是否满足斐波那契式
            else{
                long f1 = ans[ansindex-2];
                long f2 = ans[ansindex-1];
                //剪枝：当前序列的最后一个数和倒数第二个数相加已经超过int范围
                if(f1+f2 > INT_MAX)
                    return false;
                //剪枝：当前取出的数已经太大，超过序列后两个数的和
                if(cur > f1+f2)
                    return false;
                //符合条件,添加入序列
                if(cur == f1+f2){
                    ans.push_back(cur);
                    bool cur_stat = backtrack(S, sindex+l, ans, ansindex+1);
                    if(cur_stat)
                        return true;
                    ans.pop_back();
                }
            }
        }
        return false;
    }
    //把取出的数字字符串转为 int 型变量
    int my_stoi(string s){
        long ans = 0;
        int slen = s.length();
        //剪枝：取出的数有前导0
        if(slen > 1 && s[0] == '0')
            return -1;
        for(int i=0; i<slen; i++){
            ans *= 10;
            ans += (s[i]-'0');
        }
        //剪枝：取出的数超过 int 范围
        if(ans > INT_MAX)
            return -1;
        return ans;
    }
};
```

