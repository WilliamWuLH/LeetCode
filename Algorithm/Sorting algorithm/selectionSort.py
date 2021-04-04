import random
import insertionSort

def selectionsort(arr,n):
    for i in range(0,n):
        min = i
        for j in range(i+1,n):
            if arr[j] < arr[min]:
                min = j
        arr[i],arr[min] = arr[min],arr[i]

if __name__ == "__main__":
    n = input('input the size of array: ')
    arr1 = arr2 = random.sample(range(1000),int(n))
    print(arr1)
    selectionsort(arr1,int(n))
    print(arr1)
    insertionSort.insertionsort(arr2,int(n))
    print(arr2)

'''
选择排序（Selection sort）是一种简单直观的排序算法。
它的工作原理如下：
    首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
    然后，再从剩余未排序元素中继续寻找最小（大）元素，
    然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。
'''