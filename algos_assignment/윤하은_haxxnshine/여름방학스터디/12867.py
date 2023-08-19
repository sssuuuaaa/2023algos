N = int(input())
M = int(input())
dims = list(map(int, input().split()))
dir = input()

able = True
path = [{}]
cur = {}

for i in range(M):
    cur[dims[i]] = cur.get(dims[i], 0) + (1 if dir[i] == '+' else -1)
    if cur[dims[i]] == 0:            
        del cur[dims[i]]
    for cmp in path:
        if cur.items() == cmp.items(): 
            able = False
            break
    if not able:
        break
    path.append(cur.copy())           

if cur == {}: able = False   
print(1 if able else 0)
