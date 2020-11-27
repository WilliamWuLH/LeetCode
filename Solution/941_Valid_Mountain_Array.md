## Valid Mountain Array

Given an array of integers `arr`, return *`true` if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- `arr.length >= 3`

- There exists some

  ```
  i
  ```

  with 

  ```
  0 < i < arr.length - 1
  ```

   such that:

  - `arr[0] < arr[1] < ... < arr[i - 1] < A[i]`
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

**Example 1:**

```
Input: arr = [2,1]
Output: false
```

**Example 2:**

```
Input: arr = [3,5,5]
Output: false
```

**Example 3:**

```
Input: arr = [0,3,2,1]
Output: true
```

**Constraints:**

- `1 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^4`

#### 版本1：分多种情况讨论

​		分了初始状态，上升，下降，讨论各种情况下不正确的数组，并且还有状态转移的判断。

```c++
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int flag = 0;
        for(int i=0; i<A.size()-1; i++){
            if(flag == 0 && A[i] < A[i+1])
                flag = 1;
            else if(flag == 1 && A[i] > A[i+1])
                flag = 2;
            else if(A[i] == A[i+1] || (flag != 1 && A[i] < A[i+1]) || (flag == 0 && A[i] > A[i+1]))
                return false;
        }
        if(flag != 2)
            return false;
        return true;
    }
};
```

#### 版本2：双指针夹击

​		从数组头部计算上升的区域，从数组尾部计算下降的区域，最后判断是否符合。

​		重点难点：注意一定要有上升和下降的区域，不能纯上升或者纯下降。

```c++
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int head = 0, tail = A.size()-1;
        if(tail < 2)
            return false;
        while(head+1 < A.size() && A[head] < A[head+1])
            head++;
        while(tail > 0 && A[tail] < A[tail-1])
            tail--;
        return head == tail && head != 0 && tail != A.size()-1;
    }
};
```

#### 版本3：线性遍历

​		遍历数组的第一个上升和下降的区间，如果是整一个数组，则表明符合要求，如果不是则不满足。

​		重点难点：要判断是否有上升或者下降的区间，不能纯上升或者纯下降。

```c++
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int index = 0;
        while(index+1 < A.size() && A[index] < A[index+1])
            index++;
        if(index == 0 || index == A.size()-1)
            return false;
        while(index+1 < A.size() && A[index] > A[index+1])
            index++;
        return index == A.size()-1;
    }
};
```

