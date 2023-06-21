def gcd(a,b):
    temp = 0
    while b != 0:
        temp = a%b
        a = b
        b = temp
    return a

def to_fraction(left, up, down):
    print(' '*(len(str(left))+1)+str(up))
    print(str(left)+' '+'-'*len(str(down)))
    print(' '*(len(str(left))+1)+str(down))

def solution(N):
    if N == 1:
            print(1)
    elif N == 2:
            print(3)
    #N>2인경우
    else:
        a = arr[N][0] * N
        b = arr[N][1]
        div = gcd(a,b)
        left = int(a/div) // int(b/div)
        up = int(a/div) % int(b/div)
        down = int(b/div)
        to_fraction(left, up, down)

arr = [[0,0],[1,1],[3,2]]


for i in range(3,23):
    #분자
    left = arr[i-1][0] *i + arr[i-1][1]
    #분모
    right = arr[i-1][1] * i
    div = gcd(left,right)
    arr.append([int(left/div),int(right/div)])

case = []
while True:
    try:
        N = int(input())
        case.append(N)
    except:
        break

for i in case:
    solution(i)
