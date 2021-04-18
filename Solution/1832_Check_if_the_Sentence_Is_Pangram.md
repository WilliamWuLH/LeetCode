## Check if the Sentence Is Pangram

## 5734. 判断句子是否为全字母句

A **pangram** is a sentence where every letter of the English alphabet appears at least once.

Given a string `sentence` containing only lowercase English letters, return `true` *if* `sentence` *is a **pangram**, or* `false` *otherwise.*

**Example 1:**

```
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
```

**Example 2:**

```
Input: sentence = "leetcode"
Output: false
```

**Constraints:**

- `1 <= sentence.length <= 1000`
- `sentence` consists of lowercase English letters.

#### 遍历 + 统计：

```c++
class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> c(26, 0);
        int ans = 0;
        for(auto &i : s){
            int p = i-'a';
            if(c[p] == 0){
                c[p] = 1;
                ans++;
            }
            if(ans >= 26)
                return true;
        }
        return false;
    }
};
```

