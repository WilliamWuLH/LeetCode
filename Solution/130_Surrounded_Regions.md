## Surrounded Regions

#### DFS 递归：

```c++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int y = board.size();
        if(y <= 0)
            return;
        int x = board[0].size();
        for(int i=0; i<x; i++){
            dfs(board, i, 0);
            dfs(board, i, y-1);
        }
        for(int i=1; i<y-1; i++){
            dfs(board, 0, i);
            dfs(board, x-1, i);
        }
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(board[i][j] == '$')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(y < 0 || y >= board.size() || x < 0 || x >= board[0].size() || board[y][x] != 'O')
            return;
        board[y][x] = '$';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
        return;
    }
};
```

#### DFS 非递归：

```c++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int y = board.size();
        if(y <= 0)
            return;
        int x = board[0].size();
        stack<pair<int, int>> s;
        for(int i=0; i<x; i++){
            if(board[0][i] == 'O')
                s.push(pair<int, int>(0, i));
            if(board[y-1][i] == 'O')
                s.push(pair<int, int>(y-1, i));
        }
        for(int i=1; i<y-1; i++){
            if(board[i][0] == 'O')
                s.push(pair<int, int>(i, 0));
            if(board[i][x-1] == 'O')
                s.push(pair<int, int>(i, x-1));
        }
        while(!s.empty()){
            pair<int, int> temp = s.top();
            s.pop();
            board[temp.first][temp.second] = '$';
            if(temp.first-1 > 0 && board[temp.first-1][temp.second] == 'O')
                s.push(pair<int, int>(temp.first-1, temp.second));
            if(temp.first+1 < y && board[temp.first+1][temp.second] == 'O')
                s.push(pair<int, int>(temp.first+1, temp.second));
            if(temp.second-1 > 0 && board[temp.first][temp.second-1] == 'O')
                s.push(pair<int, int>(temp.first, temp.second-1));
            if(temp.second+1 < x && board[temp.first][temp.second+1] == 'O')
                s.push(pair<int, int>(temp.first, temp.second+1));
        }
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(board[i][j] == '$')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
};
```

#### BFS 非递归：

```c++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int y = board.size();
        if(y <= 0)
            return;
        int x = board[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<x; i++){
            if(board[0][i] == 'O')
                q.push(pair<int, int>(0, i));
            if(board[y-1][i] == 'O')
                q.push(pair<int, int>(y-1, i));
        }
        for(int i=1; i<y-1; i++){
            if(board[i][0] == 'O')
                q.push(pair<int, int>(i, 0));
            if(board[i][x-1] == 'O')
                q.push(pair<int, int>(i, x-1));
        }
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            board[temp.first][temp.second] = '$';
            if(temp.first-1 > 0 && board[temp.first-1][temp.second] == 'O')
                q.push(pair<int, int>(temp.first-1, temp.second));
            if(temp.first+1 < y && board[temp.first+1][temp.second] == 'O')
                q.push(pair<int, int>(temp.first+1, temp.second));
            if(temp.second-1 > 0 && board[temp.first][temp.second-1] == 'O')
                q.push(pair<int, int>(temp.first, temp.second-1));
            if(temp.second+1 < x && board[temp.first][temp.second+1] == 'O')
                q.push(pair<int, int>(temp.first, temp.second+1));
        }
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(board[i][j] == '$')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
};
```

