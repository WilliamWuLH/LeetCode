import random
import heapSort
def insertionsort(arr,n):
    for i in range(0,n):
        index = i
        for j in range(i-1,-1,-1):
            if arr[index] < arr[j]:
                arr[index],arr[j] = arr[j],arr[index]
                index = j
            else:
                break

if __name__ == "__main__":
    n = input('input the size of array: ')
    arr1 = arr2 = random.sample(range(1000),int(n))
    print(arr1)
    insertionsort(arr1,int(n))
    heapSort.heapsort(arr2,int(n))
    print(arr1)
    print(arr2)

'''
插入排序（英语：Insertion Sort）是一种简单直观的排序算法。
它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
'''