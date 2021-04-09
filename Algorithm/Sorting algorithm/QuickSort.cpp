#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

#define random(a,b) (rand()%(b-a)+a)
using namespace std;

/*

快速排序（英语：Quicksort）
    又称分区交换排序（英语：partition-exchange sort），
    简称快排，是一种被广泛运用的排序算法。

基本原理与实现
    原理：
        快速排序的工作原理是通过 分治 的方式来将一个数组排序。

        快速排序分为三个过程：

            1. 将数列划分为两部分（要求保证相对大小关系）；
            2. 递归到两个子序列中分别进行快速排序；
            3. 不用合并，因为此时数列已经完全有序。

        为了保证平均时间复杂度，一般是随机选择一个数 m 来当做两个子数列的分界。
    
    其实，快速排序没有指定应如何具体实现第一步，
        不论是选择 m 的过程还是划分的过程，都有不止一种实现方法。

性质
    稳定性：
        快速排序是一种不稳定的排序算法。

    时间复杂度：
        快速排序的最优时间复杂度和平均时间复杂度为 O(n log(n))，最坏时间复杂度为 O(n^2)。

*/

void QuickSort1(vector<int> &array, int start, int end){
    // 递归的终止情况
    if(start >= end)
        return;

    // 第一步：分成子问题
    // 初始化：
    // l = start-1：为了使 array[start, l] <= pivot 恒成立
    // r = end+1：为了使 array[r, end] >= pivot 恒成立
    int l = start-1, r = end+1, pivot = array[l + r >> 1];

    while(l < r){
        /*
            注意:
                由于使用 do-while 循环,所以 l 和 r 一定会!!!自增!!!，使得循环会继续下去，
                但是如果采用 while 循环( l 和 r 的初始化做出对应的变更)，
                l 和 r 在特殊情况下不自增的话，循环就会卡死
                例如：
                    当 array[l] 和 array[r] 都为 pivot 时, l 和 r 都不会更新,导致 while 陷入死循环
        */
        do
            l++;
        while(array[l] < pivot);
        do
            r--;
        while(array[r] > pivot);
        if(l < r)
            swap(array[l], array[r]);
    }

    // 第二步：递归处理子问题
    QuickSort1(array, start, r);
    QuickSort1(array, r+1, end);

    // 第三步：子问题合并.快排这一步不需要操作，但归并排序的核心在这一步骤
    return;
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

    //朴素快速排序
    QuickSort1(array, 0, n-1);

    for(int i=0;i<n;i++){
        cout <<array[i] <<" ";
    }
}