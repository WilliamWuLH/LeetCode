## Game of Life

#### 按照题意写：

```c++
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},
                        {0,1},{1,-1},{1,0},{1,1}};
        vector<vector<int>> ans = board;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                int count = 0;
                for(int k=0; k<8; k++){
                    int nowi = i+dir[k][0];
                    int nowj = j+dir[k][1];
                    if(nowi >= 0 && nowi < board.size() && 
                        nowj >= 0 && nowj < board[i].size()){
                        if( board[nowi][nowj] == 1)
                            count++;
                    }
                }
                if(board[i][j]){
                    if(count < 2)   ans[i][j] = 0;
                    else if(count < 4)  ans[i][j] = 1;
                    else    ans[i][j] = 0;
                }
                else if(count == 3)
                    ans[i][j] = 1;
            }
        }
        board = ans;
    }
};
```

