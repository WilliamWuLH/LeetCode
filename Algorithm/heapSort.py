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