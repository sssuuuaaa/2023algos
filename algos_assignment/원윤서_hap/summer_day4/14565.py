n, a = map(int, input().split())
d0, d1 = a, n
x0, x1 = 1, 0

while(d1):
    q = d0 // d1
    tmp = d0
    d0 = d1
    d1 = tmp - q * d1
    tmp = x0
    x0 = x1
    x1 = tmp - q * x1
    
if d0 == 1:
    if x0 <= 0:
        x0 += n
    print(n - a, x0)
else:
    print(n - a, -1)

# 출처: https://velog.io/@danbibibi/%EB%B0%B1%EC%A4%80-14565%EB%B2%88-%EC%97%AD%EC%9B%90Inverse-%EA%B5%AC%ED%95%98%EA%B8%B0
