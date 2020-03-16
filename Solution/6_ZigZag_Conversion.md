##  ZigZag Conversion 

#### 数学题：（应该是 N 而不是 Z......）

​		首先，numRows == 1 是特殊情况，答案就是原字符串。

​		讨论 numRows > 1 的情况：进行分组，如下：

​				**$**            $            **$**            $            **$**            $            **$**

​				**$        $**  $        $  **$        $**  $        $  **$        $**  $        $  **$**

​				**$    $**      $    $      **$    $**      $    $      **$    $**      $    $      **$**

​				**$**            $            **$**            $            **$**            $

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

