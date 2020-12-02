## Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.

**Example 1:**

```
Input: "hello"
Output: "holle"
```

**Example 2:**

```
Input: "leetcode"
Output: "leotcede"
```

**Note:**
The vowels does not include the letter "y".

#### 头尾双指针：

```c++
class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length()-1;
        while(left < right){
            if(s[left] == 'a'||s[left] == 'e'||s[left] == 'i'||s[left] == 'o'||s[left] == 'u'||
            s[left] == 'A'||s[left] == 'E'||s[left] == 'I'||s[left] == 'O'||s[left] == 'U'){
                while(left < right){
                    if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'||
                    s[right]=='A'||s[right]=='E'||s[right]=='I'||s[right]=='O'||s[right]=='U'){
                        char temp;
                        temp = s[left];
                        s[left] = s[right];
                        s[right] = temp;
                        right--;
                        break;
                    }
                    right--;
                }
            }
            left++;
        }
        return s;
    }
};
```

