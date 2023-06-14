#a,b의 최대공약수를 구하는 함수
def gcd(a,b):
    temp = 0
    while b != 0:
        temp = a%b
        a = b
        b = temp
    return a

#문제의 출력 형식에 맞도록 분수의 정수부, 분자, 분모를 입력받아 출력하도록 하는 함수
def to_fraction(left, up, down):
    #첫째줄: 정수부분의 길이 + 1 만큼의 공백 출력 후 분자 출력
    print(' '*(len(str(left))+1)+str(up))
    #둘째줄: 정수부분 출력 후 공백 1개 출력 후 분모 길이만큼 '-' 출력
    print(str(left)+' '+'-'*len(str(down)))
    #셋째줄: 정수부분의 길이 + 1 만큼의 공백 출력 후 분모 출력
    print(' '*(len(str(left))+1)+str(down))

#정답 = N * 조화수(harmonic numbers)
def solution(N):
    #N = 1,2인 경우 정수이므로 to_fraction이 실행되면 틀린 답이므로 예외처리
    if N == 1:
            print(1)
    elif N == 2:
            print(3)
    #N>2인경우
    else:
        #arr에서 조화수를 불러와 N을 곱한 값을 분자와 분모로 나눈 뒤 약분하고
        a = arr[N][0] * N
        b = arr[N][1]
        div = gcd(a,b)
        #정수부, 분자, 분모로 나누어 to_fraction 함수에 파라미터로 입력하여 정답을 출력함
        left = int(a/div) // int(b/div)
        up = int(a/div) % int(b/div)
        down = int(b/div)
        to_fraction(left, up, down)

#조화수를 가분수 형태로 저장한 List
arr = [[0,0],[1,1],[3,2]]

#쿠폰에 적힐 숫자의 범위가 0<N<23이고, arr에 N=2까지 저장을 했으므로 range(3,23)으로 연산 최적화
#입력값이 여러개가 주어질 수 있으므로 미리 모든 경우의 수를 연산한 후 값을 불러오는 것이 평균 속도가 빠를 것이라고 판단
#N이 작은 경우만 주어진다면 range(3,input)으로 수정해 연산 횟수를 줄일 수 있음
for i in range(3,23):
    #분자
    left = arr[i-1][0] *i + arr[i-1][1]
    #분모
    right = arr[i-1][1] * i
    #약분을 위한 최대공약수 계산
    div = gcd(left,right)
    #arr에 새로 계산한 값 append
    arr.append([int(left/div),int(right/div)])

#입력을 받기 위한 List
case = []
#입력 개수가 주어지지 않으므로 
while True:
    #EOFerror가 나타날때까지 입력받고,
    try:
        N = int(input())
        case.append(N)
    #try-except로 입력의 끝을 파악함
    except:
        break
    
#모든 입력에 대해 solution을 출력함
for i in case:
    solution(i)

# 출처: https://blog.naver.com/jinsk1884/223046205564
# [출처] [백준] - 1643 쿠폰|작성자 J J Yang
