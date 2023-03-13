n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# Sort array a
a.sort()

# Function to perform binary search
def binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid - 1
    return l

# Perform binary search for each element in array b
for bj in b:
    pos = binary_search(a, bj)
    print(pos, end=' ')
