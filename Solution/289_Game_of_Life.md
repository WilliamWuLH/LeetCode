## Game of Life

According to the [Wikipedia's article](https://en.wikipedia.org/wiki/Conway's_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a *board* with *m* by *n* cells, each cell has an initial state *live* (1) or *dead* (0). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population..
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

**Example:**

```
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
```

**Follow up**:

1. Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

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

