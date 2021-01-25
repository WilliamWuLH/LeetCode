## Regions Cut By Slashes

In a N x N `grid` composed of 1 x 1 squares, each 1 x 1 square consists of a `/`, `\`, or blank space. These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a `\` is represented as `"\\"`.)

Return the number of regions.

**Example 1:**

```
Input:
[
  " /",
  "/ "
]
Output: 2
```

**Example 2:**

```
Input:
[
  " /",
  "  "
]
Output: 1
```

**Example 3:**

```
Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
```

**Example 4:**

```
Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
```

**Example 5:**

```
Input:
[
  "//",
  "/ "
]
Output: 3
```

**Note:**

1. `1 <= grid.length == grid[0].length <= 30`
2. `grid[i][j]` is either `'/'`, `'\'`, or `' '`.

#### 并查集：

这是一个关于连通性的问题，让我们求解连通分量的个数，解决这个问题没有特别的技巧，根据题意画图分析。

「斜杠」、「反斜杠」把单元格拆分成的 2 个三角形的形态，在做合并的时候需要分类讨论。根据「斜杠」、「反斜杠」分割的特点，我们把一个单元格分割成逻辑上的 4 个部分。

我们须要遍历一次输入的二维网格 grid，在 单元格内 和 单元格间 进行合并。

**单元格内：**

1. 如果是空格：合并 0、1、2、3；
2. 如果是斜杠：合并 0、3，合并 1、2；
3. 如果是反斜杠：合并 0、1，合并 2、3。

**单元格间：**

把每一个单元格拆分成 4 个小三角形以后，相邻的单元格须要合并，无须分类讨论。我们选择在遍历 grid 的每一个单元格的时候，分别「向右、向下」尝试合并。

- 向右：合并 1 （当前单元格）和 3（当前单元格右边 1 列的单元格），上图中红色部分；
- 向下：合并 2 （当前单元格）和 0（当前单元格下边 1 列的单元格），上图中蓝色部分。

事实上，大家选择在遍历 grid 的每一个单元格的时候，分别「向左、向上」、「向左、向下」、「向右、向上」、「向右、向下」中的任何一种都可以。

合并完成以后，并查集里连通分量的个数就是题目要求的区域的个数。

**参考：[力扣 (LeetCode)](https://leetcode-cn.com/u/leetcode/)**

```c++
class DSU{
    private:
        int n;
        vector<int> f;
    public:
        DSU(int N){
            n = 4 * N * N;
            f.resize(n);
            for(int i=0; i<n; i++)
                f[i] = i;
        }
        int find(int x){
            if(x != f[x])
                f[x] = find(f[x]);
            return f[x];
        }
        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            f[x] = y;
            return;
        }
        int countset(){
            int count = 0;
            for(int i=0; i<n; i++)
                if(i == f[i])
                    count++;
            return count;
        }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int index = 4 * ((i * n) + j);
                if(grid[i][j] == '/'){
                    dsu.unionset(index, index+1);
                    dsu.unionset(index+2, index+3);
                }
                else if(grid[i][j] == '\\'){
                    dsu.unionset(index, index+3);
                    dsu.unionset(index+1, index+2);
                }
                else{
                    dsu.unionset(index, index+1);
                    dsu.unionset(index+1, index+2);
                    dsu.unionset(index+2, index+3);
                }
                if(j < n-1)
                    dsu.unionset(index+3, index+5);
                if(i < n-1)
                    dsu.unionset(index+2, index+4*n);
            }
        }
        return dsu.countset();
    }
};
```

