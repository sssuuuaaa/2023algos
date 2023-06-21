from math import log, e
gamma = 0.577215664901532
n = int(input())
if n in (1,2):
    print([0,1,3][n]); quit()
ans = log(n,e) + gamma + 1/(2*n)-1/(12*n**2)
ans += 1/(120*n**4) - 1/(252*n**6)
print(ans*n)
