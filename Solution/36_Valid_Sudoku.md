## Valid Sudoku 

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**

```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

**Example 2:**

```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

**Constraints:**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit or `'.'`.

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

