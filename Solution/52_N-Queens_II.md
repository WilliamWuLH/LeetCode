## N-Queens II

#### 回溯法 backtrack：

​		经典 N 皇后问题，找有几个解，还是回溯法 + 剪枝，每一行（或者每一列）固定只有一个皇后，给皇后选择位置。

```c++
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> used(n, 0);
        map<int, int> pos;
        backtrack(ans, used, pos, 0, n);
        return ans;
    }
    void backtrack(int &ans, vector<int> &used, map<int, int> &pos, int level, int n){
        if(level >= n){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i] != 1 && iscorrect(pos, level, i)){
                pos[level] = i;
                used[i] = 1;
                backtrack(ans, used, pos, level+1, n);
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

