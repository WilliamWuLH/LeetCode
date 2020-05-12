## Reverse Vowels of a String

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

