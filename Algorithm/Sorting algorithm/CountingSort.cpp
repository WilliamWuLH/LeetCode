#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

#define random(a,b) (rand()%(b-a)+a)
using namespace std;

/*

计数排序（英语：Counting sort）是一种线性时间的排序算法。

工作原理：
    计数排序的工作原理是使用一个额外的数组 C，
    其中第 i 个元素是待排序数组 A 中值等于 i 的元素的个数，
    然后根据数组 C 来将 A 中的元素排到正确的位置。

    它的工作过程分为三个步骤：
        1. 计算每个数出现了几次；
        2. 求出每个数出现次数的 前缀和；
        3. 利用出现次数的前缀和，从右至左计算每个数的排名。

性质
    稳定性
        计数排序是一种稳定的排序算法。

    时间复杂度
        计数排序的时间复杂度为 O(n + w)，其中 w 代表待排序数据的值域大小。

*/

const int N = 100010;
const int W = 100010;

void CountingSort(vector<int> &array, int n, int max)
{
    vector<int> count(W, 0);
    vector<int> res(n, 0);
    // 计算每个数出现了几次
    for(int i=0; i<n; i++)
        count[ array[i] ]++;
    // 求出每个数出现次数的前缀和
    for(int i=1; i<W; i++)
        count[i] += count[i-1];
    // 计算每个数的排名
    for(int i=0; i<n; i++)
        res[ --count[ array[i] ] ] = array[i];
    array = res;
}

int main()
{
    int n,max;
    cout <<"Please input the length of array and the max number: ";
    cin >>n >>max;
    // 随机取值，n 个随机数，范围 0 - max
    vector<int> array;
    for(int i=0;i<n;i++){
        array.push_back(random(0,max));
        cout <<array[i] <<" ";
    }
    cout <<endl;
    // 计数排序
    CountingSort(array, n, max);
    for(int i=0;i<n;i++){
        cout <<array[i] <<" ";
    }
}