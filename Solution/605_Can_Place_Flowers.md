## Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in **adjacent** plots.

Given an integer array `flowerbed` containing `0`'s and `1`'s, where `0` means empty and `1` means not empty, and an integer `n`, return *if* `n` new flowers can be planted in the `flowerbed` without violating the no-adjacent-flowers rule.

**Example 1:**

```
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
```

**Example 2:**

```
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

**Constraints:**

- `1 <= flowerbed.length <= 2 * 10^4`
- `flowerbed[i]` is `0` or `1`.
- There are no two adjacent flowers in `flowerbed`.
- `0 <= n <= flowerbed.length`

#### 遍历 + 贪心：

##### 解题思路：

​		遍历整个数组（花坛），找出数组中所有可以种花的位置，统计整个数组（花坛）中可以种花的最大位置数。

##### 具体实现：

​		遍历数组进行位置统计时有两个比较特殊的位置需要特殊考虑，即数组的头和尾，数组的头部可以认为左边有一个空位置，数组的尾部可以认为是右边有一个空位置，所以计算空位置时应该多算一个不能种花但是空着的位置。详细代码如下：

```c++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int len = flowerbed.size();
        for(int i=0; i<len; i++){
            if(count > -1){
                if(flowerbed[i] == 0)
                    count++;
                else{
                    n -= count/2;
                    count = -1;
                }
            }
            else if(flowerbed[i] == 0)
                count++;
        }
        if(count > -1)
            n -= (count+1)/2;
        return n <= 0;
    }
};
```

