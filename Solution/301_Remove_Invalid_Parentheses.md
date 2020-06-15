## Remove Invalid Parentheses

#### BFS 的变形：

删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。

```c++
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> parent;
        set<string> child;
        vector<string> ans;
        int len = s.length();
        if(correct(s)){
            ans.push_back(s);
            return ans;
        }
        parent.insert(s);
        set<string>::iterator it;
        while(ans.size() == 0 && len--){
            for(it=parent.begin(); it!=parent.end(); it++){
                string temp = *it;
                for(int i=0; i<temp.length(); i++){
                    string t = temp.substr(0,i) + temp.substr(i+1,temp.length()-i-1);
                    child.insert(t);
                }
            }
            for(it=child.begin(); it!=child.end(); it++){
                string temp = *it;
                if(correct(temp)){
                    ans.push_back(temp);
                }
            }
            parent = child;
            child.clear();
        }
        return ans;
    }
    bool correct(string s){
        int left = 0;
        for(auto i : s){
            if(i == '(')
                left++;
            else if(i == ')'){
                if(left <= 0)
                    return false;
                else
                    left--;
            }
        }
        if(left == 0)
            return true;
        else
            return false;
    }
};
```

