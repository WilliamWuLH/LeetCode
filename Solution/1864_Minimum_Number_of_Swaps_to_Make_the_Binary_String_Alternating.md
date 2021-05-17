## Minimum Number of Swaps to Make the Binary String Alternating

Given a binary string `s`, return *the **minimum** number of character swaps to make it **alternating**, or* `-1` *if it is impossible.*

The string is called **alternating** if no two adjacent characters are equal. For example, the strings `"010"` and `"1010"` are alternating, while the string `"0100"` is not.

Any two characters may be swapped, even if they are **not adjacent**.

**Example 1:**

```
Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.
```

**Example 2:**

```
Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.
```

**Example 3:**

```
Input: s = "1110"
Output: -1
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s[i]` is either `'0'` or `'1'`.

#### 统计 + 分类讨论：

```c++
class Solution {
public:
    int minSwaps(string s) {
        int z = 0, o = 0, n = s.length();
        int d1 = 0, d2 = 0, d = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0')
                z++;
            else if(s[i] == '1')
                o++;
            if(i % 2 && s[i] == '0')
                d1++;
            if(i % 2 && s[i] == '1')
                d2++;
        }
        if(z < n/2 || o < n/2)
            return -1;
        if(n % 2){
            if(o == n/2)
                return o - d2;
            return z - d1;
        }
        if(d1 > d2)
            return z - d1;
        return o - d2;
    }
};
```

