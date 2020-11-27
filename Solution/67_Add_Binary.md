## Add Binary

Given two binary strings `a` and `b`, return *their sum as a binary string*.

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```
Input: a = "1010", b = "1011"
Output: "10101"
```

**Constraints:**

- `1 <= a.length, b.length <= 10^4`
- `a` and `b` consist only of `'0'` or `'1'` characters.
- Each string does not contain leading zeros except for the zero itself.

#### 逐位运算：

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int aindex = a.length()-1;
        int bindex = b.length()-1;
        int carry = 0;
        string ans;
        while(aindex >= 0 || bindex >= 0){
            int abit = aindex < 0 ? 0 : a[aindex] - '0';
            int bbit = bindex < 0 ? 0 : b[bindex] - '0';
            ans += (abit + bbit + carry)%2 + '0';
            carry = (abit + bbit + carry)/2;
            aindex--;
            bindex--;
        }
        if(carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

