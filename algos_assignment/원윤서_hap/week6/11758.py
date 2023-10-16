import sys
input = sys.stdin.readline
point = []
for _ in range(3):
    point.append(list(map(int, input().split())))
    
def ccw(p1, p2, p3):
    return (p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1]) - (p2[0]*p1[1] + p3[0]*p2[1] + p1[0]*p3[1])

result = ccw(point[0], point[1], point[2])

if result > 0:
    print(1)
elif result == 0:
    print(0)
else:
    print(-1)

# 출처: https://velog.io/@jini_eun/%EB%B0%B1%EC%A4%80-11758%EB%B2%88-CCW-Java-Python
