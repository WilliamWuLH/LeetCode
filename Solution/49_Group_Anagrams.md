## Group Anagrams

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lower-case English letters.

#### 建字母表统计字母个数 + 建哈希表匹配字母个数：

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        int count = 0;
        vector<map<char,int>> match;
        vector<vector<string>> ans;
        for(int i=0; i<len; i++){
            map<char,int> temp;
            for(int j=0; j<strs[i].length(); j++)
                temp[ strs[i][j] ]++;
            int pos = 0;
            for(pos=0; pos<count; pos++){
                if(match[pos] == temp){
                    ans[pos].push_back(strs[i]);
                    break;
                }
            }
            if(pos == count){
                match.push_back(temp);
                vector<string> add;
                add.push_back(strs[i]);
                ans.push_back(add);
                count++;
            }
        }
        return ans;
    }
};
```

#### 将字符串排序 + 建哈希表存字符串和对应于答案的位置：

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        map<string,int> match;
        vector<vector<string>> ans;
        for(int i=0; i<len; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(match.count(temp))
                ans[match[temp]].push_back(strs[i]);
            else{
                match[temp] = ans.size();
                vector<string> add;
                add.push_back(strs[i]);
                ans.push_back(add);
            }
        }
        return ans;
    }
};
```

