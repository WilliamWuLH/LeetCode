import random
import heapSort

def merge(arr,l,m,r):
    temp = [0 for i in range(r-l+1)]
    count = 0
    i = l
    j = m+1
    while i <= m and j <= r:
        if arr[i] <= arr[j]:
            temp[count] = arr[i]
            i+=1
        else:
            temp[count] = arr[j]
            j+=1
        count+=1
    while i <= m:
        temp[count] = arr[i]
        count+=1
        i+=1
    while j <= r:
        temp[count] = arr[j]
        count+=1
        j+=1
    arr[l:r+1] = temp


def mergesort(arr,l,r):
    if l<r:
        m=l+int((r-l)/2)
        mergesort(arr,l,m)
        mergesort(arr,m+1,r)
        merge(arr,l,m,r)

if __name__ == "__main__":
    n = input('input the size of array: ')
    arr1 = arr2 = random.sample(range(1000),int(n))
    print(arr1)
    mergesort(arr1,0,int(n)-1)
    heapSort.heapsort(arr2,int(n))
    print(arr1)
    print(arr2)

'''
归并排序（英语：Merge sort，或mergesort），是创建在归并操作上的一种有效的排序算法。
该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
分治法:
    分割：递归地把当前序列平均分割成两半。
    集成：在保持元素顺序的同时将上一步得到的子序列集成到一起（归并）。
'''