import sys
input = sys.stdin.readline
N = int(input())
arr = []

for i in range(N):
    arr.append(tuple(map(int, input().split())))
arr.sort()
start = arr[0][0]
end = arr[0][1]
result = 0

for i in range(1, N):
    if arr[i][0] <= end < arr[i][1]:
        end = max(end, arr[i][1])

    elif arr[i][0] > end:
        result += end - start
        start = arr[i][0]
        end = arr[i][1]

result += end - start
print(result)

# 출처: https://simsim231.tistory.com/221
