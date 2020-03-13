#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#define random(a,b) (rand()%(b-a)+a)
using namespace std;

void become_heap(vector<int> &array,int start,int end)
{
    int father=start;
    int child=father*2+1;
    while(child<=end){
        if(child+1<=end && array[child]<array[child+1])
            child++;
        if(array[father]<array[child]){
            int temp=array[father];
            array[father]=array[child];
            array[child]=temp;
            father=child;
            child=father*2+1;
        }
        else
            return;
    }
}

void heapsort(vector<int> &array,int n)
{
    for(int i = n/2-1; i >= 0; i--)
        become_heap(array,i,n-1);
    for(int i = n-1; i>0; i--){
        int temp=array[0];
        array[0]=array[i];
        array[i]=temp;
        become_heap(array,0,i-1);
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
    int i=0,j=0;
    while(i<n){
        int edge=i+pow(2,j);
        for(;i<edge;i++){
            if(i>=n)
                break;
            cout <<array[i] <<" ";   
        }
        cout <<endl;
        j++;
    }
    heapsort(array,n);
    for(int i=0;i<n;i++){
        cout <<array[i] <<" ";
    }
}