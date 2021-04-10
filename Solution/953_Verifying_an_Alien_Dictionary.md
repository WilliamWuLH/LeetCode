## Verifying an Alien Dictionary

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographicaly in this alien language.

**Example 1:**

```
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
```

**Example 2:**

```
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
```

**Example 3:**

```
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 20`
- `order.length == 26`
- All characters in `words[i]` and `order` are English lowercase letters.

#### 遍历比较相邻的单词 + 字符查找定位：

​		简单题，首先遍历字符串数组，两两比较相邻的字符串，如果有序继续比较下一对，如果无序则直接返回 false。字符查找定位则是判断某个字符在给定的字符串顺序表中的位置，也是遍历判断。

细节：

- 相邻字符串可能长度不同，注意判断边界条件，不要越界。
- 某些字符串可能是另一个字符串的前缀，即一个单词是另一个单词前面的一部分。此时要判断相对顺序，即短的单词在前，长的单词在后。

```c++
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        for(int i=0; i<n-1; i++){
            int s1=0, s2=0, l1=words[i].length(), l2=words[i+1].length();
            while(s1 < l1 && s2 < l2 && words[i][s1] == words[i+1][s2]){
                s1++;
                s2++;
            }
            if(s1 == l1 || s2 == l2){
                if(l1 > l2)
                    return false;
                else
                    continue;
            }
            s1 = locate(order, words[i][s1]);
            s2 = locate(order, words[i+1][s2]);
            if(s1 > s2)
                return false;
        }
        return true;
    }
    int locate(const string &s, const char &c){
        int pos=0;
        while(s[pos] != c)
            pos++;
        return pos;
    }
};
```

