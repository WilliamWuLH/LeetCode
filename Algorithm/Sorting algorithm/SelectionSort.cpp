#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

#define random(a,b) (rand()%(b-a)+a)
using namespace std;

/*

选择排序（英语：Selection sort）是排序算法的一种，
    它的工作原理是每次找出第 i 小的元素（也就是 Array(i..n) 中最小的元素），
    然后将这个元素与数组第 i 个位置上的元素交换。

性质
    稳定性：
        由于 swap（交换两个元素）操作的存在，选择排序是一种不稳定的排序算法。

    时间复杂度：
        选择排序的最优时间复杂度、平均时间复杂度和最坏时间复杂度均为 O(n^2)。

*/

void SelectionSort(vector<int> &array, int n){
    // 遍历每个位置，选出第 i 小的数
    for(int i=0; i<n; i++){
        int min = i;
        // 找出第 i 小的数
        for(int j=i+1; j<n; j++)
            if(array[j] < array[min])
                min = j;
        // 把第 i 小的数交换到位置 i
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
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
    // 选择排序
    SelectionSort(array, n);
    for(int i=0;i<n;i++){
        cout <<array[i] <<" ";
    }
}