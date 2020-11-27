## Letter Combinations of a Phone Number

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

**Example 1:**

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```
Input: digits = ""
Output: []
```

**Example 3:**

```
Input: digits = "2"
Output: ["a","b","c"]
```

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

#### 哈希表 + 深度优先搜索：

​		使用递归函数进行深度优先搜索。

```c++
class Solution {
public:
    map<char,string> hash = {{'2',"abc"},{'3',"def"},{'4',"ghi"},
                            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
                            {'8',"tuv"},{'9',"wxyz"}};

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string now = "";
        if(digits.length() == 0)
            return ans;
        Depthsort(0,now,digits,ans);
        return ans;
    }

    void Depthsort(int pos,string now,string digits,vector<string> &ans){
        if(pos == digits.length()){
            ans.push_back(now);
            return;
        }
        char num = digits[pos];
        int len = hash[num].length();
        for(int i=0;i<len;i++){
            now += hash[num][i];
            Depthsort(pos+1,now,digits,ans);
            now = now.substr(0,now.length()-1);
        }
    }
};
```

