def quickSort(arr, left, right):
    i = left
    j = right
    pivot = arr[left]

    while(i<=j):
        while(arr[i] < pivot):
            i+=1
        while(arr[j] > pivot):
            j-=1
        if(i<=j):
            arr[i],arr[j] = arr[j],arr[i]
            i+=1
            j-=1
    
    if(left<j):
        quickSort(arr,left,j)
    if(right>i):
        quickSort(arr,i,right )

lol = [8,5,3,0,22,7,44,99,1]

quickSort(lol, 0, len(lol)-1)

print(lol)

print(lol[-5:][::-1])