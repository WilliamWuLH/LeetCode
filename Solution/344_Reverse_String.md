## Reverse String

Write a function that reverses a string. The input string is given as an array of characters `char[]`.

Do not allocate extra space for another array, you must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

You may assume all the characters consist of [printable ascii characters](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

**Example 1:**

```
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**Example 2:**

```
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

#### 头尾元素互换：

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1)
            return;
        int pos = 0;
        while(pos < s.size()/2){
            char temp;
            temp = s[pos];
            s[pos] = s[s.size()-1-pos];
            s[s.size()-1-pos] = temp;
            pos++;
        }
        return;
    }
};
```

