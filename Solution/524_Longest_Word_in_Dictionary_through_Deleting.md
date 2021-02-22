## Longest Word in Dictionary through Deleting

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

**Example 1:**

```
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
```

**Example 2:**

```
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
```

**Note:**

1. All the strings in the input will only contain lower-case letters.
2. The size of the dictionary won't exceed 1,000.
3. The length of all the strings in the input won't exceed 1,000.

#### 遍历字符串字典 + 逐个判断：

​		题目给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

​		所以我们可以直接遍历整个字符串字典，取出里面的字符串和题目给定字符串进行判断比较。首先需要判断取出的字符串是不是可以通过删除给定字符串的某些字符来得到，我们可以使用指针移动进行判断。接着判断当前符合条件的字符串和答案的区别，选出长度最长且字典顺序最小的字符串作为答案。

```c++
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        int len = s.length();
        for(auto &cur : d){
            int i = 0, j = 0, n = cur.length();
            while(i < n && j < len){
                if(s[j] == cur[i])
                    i++;
                j++;
            }
            if(i >= n && (n > ans.length() || (n == ans.length() && cur < ans)))
                ans = cur;
        }
        return ans;
    }
};
```

