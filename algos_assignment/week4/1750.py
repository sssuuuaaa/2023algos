import sys
import math
mod = 10000003
input = sys.stdin.readline

n = int(input())
a = [int(input()) for _ in range(n)]
ans = 0
SZ = max(a) + 1
dp = [0] * SZ
for i in range(n):
    for j in range(1, SZ):
        if dp[j]: dp[math.gcd(j, a[i])] += dp[j]
    dp[a[i]] += 1
print(dp[1] % mod)

# 출처: https://gubshig.tistory.com/12
