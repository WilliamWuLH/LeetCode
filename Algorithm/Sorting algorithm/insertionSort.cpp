#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

#define random(a,b) (rand()%(b-a)+a)
using namespace std;

/*

插入排序（英语：Insertion sort）是一种简单直观的排序算法。
    它的工作原理为将待排列元素划分为 “已排序” 和 “未排序” 两部分，
    每次从 “未排序的” 元素中选择一个插入到 “已排序的” 元素中的正确位置。

性质
    稳定性：
        插入排序是一种稳定的排序算法。

    时间复杂度：
        插入排序的最优时间复杂度为 O(n)，在数列几乎有序时效率很高。
        插入排序的最坏时间复杂度和平均时间复杂度都为 O(n^2)。

*/


void IncertionSort(vector<int> &array,int n)
{
    for(int i=1; i<n; i++){
        // 要插入的元素值
        int cur = array[i];
        // 要插入的位置的**前一个位置**
        int pos = i-1;
        // 当前 pos 的值比要插入的值 cur 大，pos 的值需要后移
        // 并且 pos 要向前找更小的位置
        while(pos >= 0 && array[pos] > cur){
            array[pos+1] = array[pos];
            pos--;
        }
        // 在 pos + 1 的位置插入的元素值
        array[pos+1] = cur;
    }
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
    // 插入排序
    IncertionSort(array,n);
    for(int i=0;i<n;i++){
        cout <<array[i] <<" ";
    }
}