from bisect import bisect # 이진 탐색 구현 함수
import sys
input = sys.stdin.readline
n = int(input())
s = list(map(int, input().split()))
dp = [s[0]]

for i in range(1, n):
    if (s[i] > dp[-1]):
        dp.append(s[i])
    else:
        dp[bisect(dp, s[i])] = s[i]
        
print(len(dp))

# 출처: https://pacific-ocean.tistory.com/353
