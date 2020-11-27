## Short Encoding of Words

Given a list of words, we may encode it by writing a reference string `S` and a list of indexes `A`.

For example, if the list of words is `["time", "me", "bell"]`, we can write it as `S = "time#bell#"` and `indexes = [0, 2, 5]`.

Then for each index, we will recover the word by reading from the reference string from that index until we reach a `"#"` character.

What is the length of the shortest reference string S possible that encodes the given words?

**Example:**

```
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
```

**Note:**

1. `1 <= words.length <= 2000`.
2. `1 <= words[i].length <= 7`.
3. Each word has only lowercase letters.

#### 方法一：后缀字典树 Trie

```c++

```



#### 方法二：反转字符串 + 字典序排序

```c++
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        int len = words.size();
        for(int i=0; i<len; i++){
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end());
        for(int i=0; i<len-1; i++){
            if(! words[i+1].find(words[i]))
                continue;    
            ans += words[i].length() + 1;
        }
        ans += words[len-1].length() + 1;
        return ans;
    }
};
```

