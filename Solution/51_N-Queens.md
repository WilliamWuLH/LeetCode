## N-Queens

#### 回溯法：

​		经典 N 皇后问题，每一行（或者每一列）固定只能有一个皇后，先确定位置的皇后会限制后面的皇后选择位置，所以每一层都选择一个合法位置进行判断，不行就回溯，可以就继续。

​		最后就是得到每一个皇后的位置，然后把她们的位置转化为字符串的图。

```c++
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        map<int, int> pos;
        vector<int> used(n, 0);
        backtrack(ans, pos, used, 0, n);
        return ans;
    }
    void backtrack(vector<vector<string>> &ans, map<int, int> &pos, vector<int> &used, int level, int n){
        if(level >= n){
            vector<string> temp;
            for(int i=0; i<n; i++){
                string s;
                for(int j=0; j<pos[i]; j++)
                    s += ".";
                s += "Q";
                for(int j=pos[i]+1; j<n; j++)
                    s += ".";
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i] != 1 && iscorrect(pos, level, i)){
                pos[level] = i;
                used[i] = 1;
                backtrack(ans, pos, used, level+1, n);
                used[i] = 0;
            }
        }
    }
    bool iscorrect(map<int, int> &pos, int level, int now){
        for(int i=0; i<level; i++){
            if(abs(level-i) == abs(now-pos[i]))
                return false;
        }
        return true;
    }
};
```

