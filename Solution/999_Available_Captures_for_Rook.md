## Available Captures for Rook

#### 分类讨论：

```c++
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int pos1,pos2, ans = 0;
        for(pos1 = 0; pos1 < 8; pos1++){
            for(pos2 = 0; pos2 < 8; pos2++){
                if(board[pos1][pos2] == 'R')
                    break;
            }
            if(pos2 != 8)
                break;
        }
        for(int i=pos1-1; i>=0; i--){
            if(board[i][pos2] == 'p'){
                ans++;
                break;
            }
            else if(board[i][pos2] == 'B')
                break;
        }
        for(int i=pos1+1; i<8; i++){
            if(board[i][pos2] == 'p'){
                ans++;
                break;
            }
            else if(board[i][pos2] == 'B')
                break;
        }
        for(int i=pos2-1; i>=0; i--){
            if(board[pos1][i] == 'p'){
                ans++;
                break;
            }
            else if(board[pos1][i] == 'B')
                break;
        }
        for(int i=pos1+1; i<8; i++){
            if(board[pos1][i] == 'p'){
                ans++;
                break;
            }
            else if(board[pos1][i] == 'B')
                break;
        }
        return ans;
    }
};
```

