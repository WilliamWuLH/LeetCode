## Word Search

#### 深度优先搜索 DFS + 回溯法：

​			很好理解的回溯法，对就继续走下去，不对就回到之前的状态另找一条路走。

​			根据题目的意思按照题目的走路方式写代码就对了。

​			代码长了点，因为是完全按照 DFS 时可能遇到的各种情况进行分类讨论了。

```c++
class Solution {
public:
    bool ans = false;
    vector<vector<int>> use;
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            vector<int> temp;
            use.push_back(temp);
            for(int j = 0; j < board[i].size(); j++){
                use[i].push_back(0);
            }
        }
        backtrack(0, 0, 0, board, word);
        return ans;
    }
    void backtrack(int num, int pos1, int pos2, vector<vector<char>>& board, string word){
        if(ans)
            return;
        else if(num >= word.length()){
            ans = true;
            return;
        }
        else if(num == 0){
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j] == word[0]){
                        use[i][j] = 1;
                        backtrack(1, i, j, board, word);
                        use[i][j] = 0;
                    }
                }
            }
        }
        else{
            if(pos1 > 0 && board[pos1-1][pos2] == word[num] && use[pos1-1][pos2] != 1){
                use[pos1-1][pos2] = 1;
                backtrack(num+1, pos1-1, pos2, board, word);
                use[pos1-1][pos2] = 0;
            }
            if(pos1 < board.size()-1 && board[pos1+1][pos2] == word[num] 
                                    && use[pos1+1][pos2] != 1){
                use[pos1+1][pos2] = 1;
                backtrack(num+1, pos1+1, pos2, board, word);
                use[pos1+1][pos2] = 0;
            }
            if(pos2 > 0 && board[pos1][pos2-1] == word[num] && use[pos1][pos2-1] != 1){
                use[pos1][pos2-1] = 1;
                backtrack(num+1, pos1, pos2-1, board, word);
                use[pos1][pos2-1] = 0;
            }
            if(pos2 < board[pos1].size()-1 && board[pos1][pos2+1] == word[num] 
                                    && use[pos1][pos2+1] != 1){
                use[pos1][pos2+1] = 1;
                backtrack(num+1, pos1, pos2+1, board, word);
                use[pos1][pos2+1] = 0;
            }
        }
        return;
    }
};
```

