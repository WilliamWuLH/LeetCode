## Flipping an Image

Given a binary matrix `A`, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed. For example, flipping `[1, 1, 0]` horizontally results in `[0, 1, 1]`.

To invert an image means that each `0` is replaced by `1`, and each `1` is replaced by `0`. For example, inverting `[0, 1, 1]` results in `[1, 0, 0]`.

**Example 1:**

```
Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
```

**Example 2:**

```
Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
```

**Notes:**

- `1 <= A.length = A[0].length <= 20`
- `0 <= A[i][j] <= 1`

#### 翻转图像：

​		题目给定一个二进制矩阵 A，需要先水平翻转图像，然后反转图像并返回结果。

​		水平翻转图片就是将图片的每一行都进行翻转，即逆序。

​		反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。

```c++
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &i : A){
            reverse(i.begin(), i.end());
            for(auto &j : i)
                j = !j;
        }
        return A;
    }
};
```

#### 翻转图像：逐行遍历 + 双指针

​		题目给定一个二进制矩阵 A，需要先水平翻转图像，然后反转图像并返回结果。

​		水平翻转图片就是将图片的每一行都进行翻转，即逆序。

​		反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。

​		对矩阵的每一行进行操作，可以将水平翻转和反转图片同时进行，双指针中左指针指向行的行首，右指针指向行的行尾。

- 当左指针还小于右指针时，如果左指针指向的数和右指针指向的数不相同，则在水平翻转和反转图片之后依然不变，所以不用操作，但是当左指针指向的数和右指针指向的数相同时，则左右指针指向的数都需要进行反转。完成之后左指针向右移，同时右指针向左移。

- 当左指针和右指针相等时，即指向同一个数，则这个数需要进行反转。

```c++
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &i : A){
            int l = 0, r = i.size() - 1;
            while(l < r){
                if(i[l] == i[r]){
                    i[l] = !i[l];
                    i[r] = !i[r];
                }
                l++;
                r--;
            }
            if(l == r)
                i[l] = !i[l];
        }
        return A;
    }
};
```

