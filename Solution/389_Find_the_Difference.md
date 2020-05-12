## Find the Difference

#### 位运算——异或：

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = '\0';
        for(auto i : s)
            ans ^= i;
        for(auto i : t)
            ans ^= i;
        return ans;
    }
};
```

#### ASCII 码：

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(auto i : s)
            ans += i;
        for(auto i : t)
            ans -= i;
        return (char)-ans;
    }
};
```

