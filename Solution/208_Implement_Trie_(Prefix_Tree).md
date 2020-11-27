## Implement Trie (Prefix Tree)

Implement a trie with `insert`, `search`, and `startsWith` methods.

**Example:**

```
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
```

**Note:**

- You may assume that all inputs are consist of lowercase letters `a-z`.
- All inputs are guaranteed to be non-empty strings.

#### Trie 前缀树：

​		由于所有的输入都是由小写字母 `a-z` 构成的，所以我干脆一个树结点定义有26个孩子结点。

​		树结点的 end 变量表示一个 word 在这个结点结束，方便进行 search 判断。

```c++
class Trie {
private:
    struct ListNode{
        int end;
        ListNode * child[26];
    };
    ListNode * head = NULL;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new ListNode;
        for(int k=0; k<26; k++)
            head->child[k] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.length();
        ListNode * index = head;
        for(int i=0; i<len; i++){
            int pos = word[i] - 'a';
            if(index->child[pos] == NULL){
                index->child[pos] = new ListNode;
                for(int k=0; k<26; k++)
                    index->child[pos]->child[k] = NULL;
            }
            index = index->child[pos];
        }
        index->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.length();
        ListNode * index = head;
        for(int i=0; i<len; i++){
            int pos = word[i] - 'a';
            if(index->child[pos] == NULL)
                return false;
            index = index->child[pos];
        }
        if(index->end == 1)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.length();
        ListNode * index = head;
        for(int i=0; i<len; i++){
            int pos = prefix[i] - 'a';
            if(index->child[pos] == NULL)
                return false;
            index = index->child[pos];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

