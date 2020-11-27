## Rectangle Area

Find the total area covered by two **rectilinear** rectangles in a **2D** plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

**Example:**

```
Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
```

**Note:**

Assume that the total area is never beyond the maximum possible value of **int**.

#### 分类讨论：

​		重点难点：

1. 每一种情况都必须要讨论到（画图辅助）。
2. 最后返回值时一定一定要注意不能溢出！

```c++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = 0, y = 0;
        x = compare(A, C, E, G);
        y = compare(B, D, F, H);
        return (C-A)*(D-B) - x*y + (G-E)*(H-F);
    }
    int compare(int x1,int x2, int x3, int x4){
        int ans = 0;
        if(x4 <= x1 || x3 >= x2)
            ans = 0;
        else if(x4 < x2)
            ans = x4 - max(x1, x3);
        else if(x4 >= x2)
            ans = x2 - max(x1, x3);
        return ans;
    }
};
```

