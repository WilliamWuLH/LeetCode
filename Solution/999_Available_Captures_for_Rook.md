## Available Captures for Rook

On an 8 x 8 chessboard, there is one white rook. There also may be empty squares, white bishops, and black pawns. These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies. Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

**Example 1:**

```
Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.
```

**Example 2:**

```
Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 0
Explanation: 
Bishops are blocking the rook to capture any pawn.
```

**Example 3:**

```
Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
The rook can capture the pawns at positions b5, d6 and f5.
```

**Note:**

1. `board.length == board[i].length == 8`
2. `board[i][j]` is either `'R'`, `'.'`, `'B'`, or `'p'`
3. There is exactly one cell with `board[i][j] == 'R'`

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

