import sys
input = sys.stdin.readline

n, m = map(int,input().split())
# arr = [0] + [tuple(map(int,input().split())) for _ in range(m)]

# dp[i][j] => i챕터, j일 까지 검사했을 때 읽을 수 있는 최대 페이지 수
dp = [[0] * (n + 1) for _ in range(m + 1)]

for i in range(1, m + 1):
    day, page = map(int,input().split())

    for j in range(1, n + 1):
        # 챕터를 읽을 수 있는 경우
        if j - day >= 0:
            # max(챕터를 읽지 않는 경우, 챕터를 읽는 경우)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - day] + page)

        else:
            dp[i][j] = dp[i - 1][j]

print(dp[-1][-1])

# 출처: https://itsjh.tistory.com/33
