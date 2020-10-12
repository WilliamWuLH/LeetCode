## Valid Palindrome

#### 验证回文串：

​		分多种情况进行讨论，注意不区分大小写，并且只考虑字母和数字字符。

```c++
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        int left = 0, right = s.length()-1;
        bool ans = true;
        while(left < right){
            while(left < right && isok(s[left]) )   left++;
            while(left < right && isok(s[right]))  right--;
            if(s[left] >= 'A' && s[left] <= 'Z')   s[left] = s[left] - 'A' + 'a';
            if(s[right] >= 'A' && s[right] <= 'Z')  s[right] = s[right] - 'A' + 'a';
            // cout <<s[left] <<' ' <<s[right] <<endl;
            if(s[left] != s[right]){
                ans = false;
                break;
            }
            left++;
            right--;
        }
        return ans;
    }
    bool isok(char c){
        if(c >= '0' && c <= '9')
            return false;
        else if(c >= 'a' && c <= 'z')
            return false;
        else if(c >= 'A' && c <= 'Z')
            return false;
        return true;
    }
};
```

