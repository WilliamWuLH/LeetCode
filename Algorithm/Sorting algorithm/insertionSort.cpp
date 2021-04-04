#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

#define random(a,b) (rand()%(b-a)+a)
using namespace std;

void incertionsort(vector<int> &arr,int n)
{
    for(int i=0;i<n;i++){
        int index = i;
        for(int j=i-1;j>=0;j--){
            if(arr[index] < arr[j]){
                int temp=arr[index];
                arr[index]=arr[j];
                arr[j]=temp;
                index = j;
            }
        }
    }
}

int main()
{
    int n,max;
    cout <<"Please input the length of array and the max number: ";
    cin >>n >>max;
    vector<int> array;
    for(int i=0;i<n;i++){
        array.push_back(random(0,max));
        cout <<array[i] <<" ";
    }
    cout <<endl;

    incertionsort(array,n);
    for(int i=0;i<n;i++){
        cout <<array[i] <<" ";
    }
}