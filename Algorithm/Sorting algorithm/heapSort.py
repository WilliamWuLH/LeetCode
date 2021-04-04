import random
def make_heap(arr,n,i):
    father = i
    child = 2*i+1
    if child < n:
        if child+1 < n and arr[child] < arr[child+1]:
            child+=1
        if arr[father] < arr[child]:
            arr[father],arr[child] = arr[child],arr[father]
            make_heap(arr,n,child)

def heapsort(arr,n):
    for i in range(int(n+1/2),-1,-1):
        make_heap(arr,n,i)
    for i in range(n-1,0,-1):
        arr[0],arr[i] = arr[i],arr[0]
        make_heap(arr,i,0)

if __name__ == "__main__":
    n = input('input the size of array: ')
    arr = random.sample(range(1000),int(n))
    print(arr)
    heapsort(arr,int(n))
    print(arr)

'''
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
堆是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
堆排序可以说是一种利用堆的概念来排序的选择排序。
插入一个结点（尾部）：上拉/上浮
删除一个结点（根节点）：下拉/下沉
构建有序堆：局部有序-->整体有序，从最后一个非叶子结点开始下沉，直到根节点
'''