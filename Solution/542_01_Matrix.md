## 01 Matrix

#### 方法一：宽度优先搜索 BFS：

```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        typedef pair<int, int> pos;
        int vlen = matrix.size();
        int hlen = matrix[0].size();
        vector<vector<int>> ans(vlen, vector<int>(hlen, 0));
        for(int i=0; i<vlen; i++){
            for(int j=0; j<hlen; j++){
                queue<pos> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    pos thepos = q.front();
                    q.pop();
                    if( matrix[thepos.first][thepos.second] == 0){
                        ans[i][j] = abs(thepos.first-i) + abs(thepos.second-j);
                        break;
                    }
                    for(int k=0; k<4; k++){
                        int nexti = thepos.first+dir[k][0];
                        int nextj = thepos.second+dir[k][1];
                        if(nexti >= 0 && nexti < vlen && nextj >= 0 && nextj < hlen)
                            q.push(make_pair(nexti, nextj));
                    }
                }
            }
        }
        return ans;
    }
};
```

#### 方法二：动态规划：

```c++

```

