## Word Ladder

Given two words (*beginWord* and *endWord*), and a dictionary's word list, find the length of shortest transformation sequence from *beginWord* to *endWord*, such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list.

**Note:**

- Return 0 if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- You may assume no duplicates in the word list.
- You may assume *beginWord* and *endWord* are non-empty and are not the same.

**Example 1:**

```
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```

**Example 2:**

```
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

#### 递归法：超时

​		情况过多，不适合使用递归法

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
            return 1;
        int ans = INT_MAX;
        for(int i=0; i<beginWord.length(); i++){
            string temp = beginWord;
            temp.erase(i,1);
            cout <<temp <<endl;
            for(int j=0; j<wordList.size(); j++){
                string cur = wordList[j], next = wordList[j];
                cur.erase(i,1);
                if(temp == cur){
                    wordList.erase(wordList.begin()+j);
                    int res = ladderLength(next, endWord, wordList);
                    wordList.insert(wordList.begin()+j, next);
                    if(res != 0 && ans > res+1)
                        ans = res+1;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```

#### 双端广度优先搜索 BFS：

​		详见代码！

​		仅需要使用 unordered_set 对两端可以拓展的结点进行存储。

​		重点难点：

- 去重，避免重复计算。
- 判断何时满足条件可以退出。

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)    //开始就是结束
            return 1;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())  //根本没法结束
            return 0;
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> beginside{beginWord}; //记录开始端 BFS 扩展到的结点
        unordered_set<string> endside{endWord}; //记录结束端 BFS 扩展到的结点
        int ans = 1;
        while(!beginside.empty()){
            unordered_set<string> temp;
            ans++;
            for(auto s : beginside) //去重，避免重复计算
                words.erase(s);
            for(auto b : beginside){
                cout <<b <<endl;
                for(auto w : words){    //判断此时可以扩展的单词有哪些
                    int count = 0;
                    for(int i=0; i<b.length(); i++){
                        if(b[i] != w[i])
                            count++;
                        if(count > 1)
                            break;
                    }
                    if(count == 1){
                        if(endside.find(w) != endside.end())    //扩展的单词已经是结束端的单词，结束
                            return ans;
                        temp.insert(w); //还没扩展到结束端的单词，继续
                    }
                }
            }
            if(temp.size() < endside.size()){   //找到最小的队列进行扩展
                beginside = temp;
            }
            else{
                beginside = endside;
                endside = temp;
            }
        }
        return 0;
    }
};
```

