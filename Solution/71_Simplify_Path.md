## Simplify Path

Given an **absolute path** for a file (Unix-style), simplify it. Or in other words, convert it to the **canonical path**.

In a UNIX-style file system, a period `'.'` refers to the current directory. Furthermore, a double period `'..'` moves the directory up a level.

Note that the returned canonical path must always begin with a slash `'/'`, and there must be only a single slash `'/'` between two directory names. The last directory name (if it exists) **must not** end with a trailing `'/'`. Also, the canonical path must be the **shortest** string representing the absolute path.

**Example 1:**

```
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
```

**Example 2:**

```
Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
```

**Example 3:**

```
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
```

**Example 4:**

```
Input: path = "/a/./b/../../c/"
Output: "/c"
```

**Constraints:**

- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
- `path` is a valid Unix path.

#### 2021.2.5 再回首：栈

​		新写的代码，更加简洁！

​		把一层一层的打开的文件夹看作是栈，此题就相当简单了，只剩下字符串的处理。

```c++
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> p;
        string cur = "";
        path += "/";
        for(auto &i : path){
            if(i != '/')
                cur += i;
            else{
                if(cur == ".." && !p.empty())
                    p.pop();
                else if(cur != "" && cur != "." && cur != "..")
                    p.push(cur);
                cur = "";
            }
        }
        cur = "";
        while(!p.empty()){
            cur = "/" + p.top() + cur;
            p.pop();
        }
        return cur == "" ? "/" : cur;
    }
};
```

#### 文件夹的路径——栈：

​		把一层一层的打开的文件夹看作是栈，此题就相当简单了，只剩下字符串的处理。

```c++
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> folder;
        int pos = 0;
        string name = "";
        path += "/";
        while(pos < path.length()){
            if(path[pos] == '/' && name.length()){
                if(name == ".."){
                    if(!folder.empty())
                        folder.pop();
                }
                else if(name != ".")
                    folder.push(name);
                name = "";
            }
            else if(path[pos] != '/')
                name += path[pos];
            pos++;
        }
        if(folder.empty())
            return "/";
        else{
            while(!folder.empty()){
                string temp = folder.top();
                folder.pop();
                name = "/" + temp + name;
            }
        }
        return name;
    }
};
```

