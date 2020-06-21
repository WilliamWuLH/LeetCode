## Valid Sudoku 

#### 分块讨论 + 状态压缩：

​		分块讨论：将 9 * 9 的数独分成 9 个 3 * 3 的块，对每个块进行讨论，并记录已经存在的数字。

​		状态压缩：使用二进制的位数来保存已经存在的数字，节省空间资源。

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int h[9], v[9], s[9];
        memset(h, 0, 9*sizeof(int));
        memset(v, 0, 9*sizeof(int));
        memset(s, 0, 9*sizeof(int));
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){
                        if(board[i+x][j+y] == '.')
                            continue;
                        int temp = 1 << (board[i+x][j+y] - '1');
                        if((h[i+x] & temp) > 0)
                            return false;
                        else
                            h[i+x] += temp;
                        if((v[j+y] & temp) > 0)
                            return false;
                        else
                            v[j+y] += temp;
                        if(s[board[i+x][j+y] - '1'] == 1)
                            return false;
                        else
                            s[board[i+x][j+y] - '1'] = 1;
                    }
                }
                memset(s, 0, 9*sizeof(int));
            }
        }
        return true;
    }
};
```

