##  ZigZag Conversion 

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string s, int numRows);
```

**Example 1:**

```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

**Example 2:**

```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

**Example 3:**

```
Input: s = "A", numRows = 1
Output: "A"
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- `1 <= numRows <= 1000`

#### 数学题：（应该是 N 而不是 Z......）

​		首先，numRows == 1 是特殊情况，答案就是原字符串。

​		讨论 numRows > 1 的情况：进行分组，如下：

​			0：**0**------------6------------**12**------------18------------

​			1：**1**------**5**----7------11---**13**------**17**---19-------23

​			2：**2**---**4**-------8---10------**14**---**16**------20---22

​			3：**3**------------9------------**15**------------21

​		每一组的个数：(numRows - 2) * 2 + 2

​		取第 i 行：

​			i = 1 或者 i = numRows-1（最顶行 or 最底行，一组只有一个）：间隔为一个分组的字符数；

​			i != 0 && i != numRows-1（中间行，一组有两个）：

​					第一个：i，		第二个：一个分组的字符数 - i

```c++
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int len = s.length();
        int next = (numRows - 2) * 2 + 2;
        if(numRows == 1)
            return s;
        for(int i=0;i<numRows;i++){
            int pos = 0;
            while(pos + i < len){
                ans += s[pos + i];
                if(i != 0 && i != numRows-1 && pos + next - i < len)
                    ans += s[pos + next - i];
                pos += next;
            }
        }
        ans[len] = '\0';
        return ans;
    }
};
```

