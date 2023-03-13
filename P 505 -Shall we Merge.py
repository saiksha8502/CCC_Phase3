def merge_sort(A, start, end, B):
    if start == end:
        return 0
    
    mid = (start + end) // 2
    inversions = merge_sort(A, start, mid, B) + merge_sort(A, mid+1, end, B)
    
    i, j, k = start, mid+1, start
    while i <= mid and j <= end:
        if A[i] <= A[j]:
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1
            inversions += (mid - i + 1)
        k += 1
        
    while i <= mid:
        B[k] = A[i]
        i += 1
        k += 1
        
    while j <= end:
        B[k] = A[j]
        j += 1
        k += 1
        
    for i in range(start, end+1):
        A[i] = B[i]
        
    return inversions

n = int(input())
A = [int(input()) for _ in range(n)]
B = [0] * n

inversions = merge_sort(A, 0, n-1, B)
print(inversions)
