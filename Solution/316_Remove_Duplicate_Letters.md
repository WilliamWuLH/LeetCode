## Remove Duplicate Letters

Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is **the smallest in lexicographical order** among all possible results.

**Note:** This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

**Example 1:**

```
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```
Input: s = "cbacdcbc"
Output: "acdb"
```

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.

#### 感悟：这种  去除字符串（数组等）中的部分元素  并  返回最小值（最小字典序）  的题目，一般都用  单调栈  的思想。

##### 不同点：去除字符串（数组等）中元素的条件、单调栈中弹出栈顶元素的条件、添加单调栈栈顶元素的条件

#### 单调栈：

​		这道题的题解我们采用上述列出的不同点来思考：

​		->  **去除字符串中元素的条件**：字符串中存在重复的字符

​		->  **单调栈中弹出栈顶元素的条件**：单调栈中已经有元素，并且单调栈中栈顶元素大于当前遍历到的字符，并且单调栈的栈顶元素在字符串中还有剩余的字符（即后面的遍历过程中还有这个字符出现）

​		->  **添加单调栈栈顶元素的条件**：当前遍历到的字符在单调栈中不存在（可能是第一次遍历到或者是之前被弹出了）

最后的单调栈就是答案。

##### 开始解题：

通过**去除字符串中元素的条件**，我们可以建立一个 count 数组，统计字符串中剩余的各个字符的数目，当某个字符的剩余数目为 0 时，说明这个字符不能在单调栈中弹出了。

通过**单调栈中弹出栈顶元素的条件**，我们可以在每次遍历到一个字符串的字符时，使用 while 循环进行判断并且弹出栈顶元素，维持单调栈的**单调性**。

通过**添加单调栈栈顶元素的条件**，我们通过判断字符是否在单调栈中完成，如果不在单调栈中，就需要添加。

注意：每次遍历到字符串的一个字符时，记得更新 count 剩余的各个字符的个数。

```c++
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26];
        memset(count, 0, sizeof(int)*26);
        vector<char> stack;
        for(auto &c : s)
            count[c-'a']++;
        for(auto &c : s){
            if(find(stack.begin(), stack.end(), c) == stack.end()){
                while(!stack.empty() && stack.back() > c && count[stack.back()-'a'])
                    stack.pop_back();
                stack.push_back(c);
            }
            count[c-'a']--;
        }
        s = "";
        for(auto &c : stack)
            s += c;
        return s;
    }
};
```

