## Simplify Path

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

