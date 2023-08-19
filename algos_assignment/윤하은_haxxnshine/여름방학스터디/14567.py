import sys
from collections import deque

def topology_sort():
    q = deque()
    
    for i in range(n):
        if indegree[i] == 0: 
            q.append(i)
   
    while q:
        now = q.popleft()
        for i in graph[now]: 
            indegree[i] -= 1
            if indegree[i] == 0:  
                result[i] = result[now] + 1  
                q.append(i)

    print(*result)

n, m = map(int, sys.stdin.readline().split()) 
indegree = [0] * n
result = [1] * n
graph = [[] for i in range(n)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a - 1].append(b - 1)  
    indegree[b - 1] += 1   

topology_sort()
