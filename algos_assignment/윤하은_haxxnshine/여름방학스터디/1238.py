import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)
N, M, X = map(int, input().split())
Dis = [INF] * (N + 1)
Dis_Rev = [INF] * (N + 1) 
Dis[X] = 0
Dis_Rev[X] = 0
Graph = [[] for _ in range(N + 1)] 
Graph_Rev = [[] for _ in range(N + 1)] 
for _ in range(M):
    a, b, c = map(int, input().split())
    Graph[a].append((b, c))
    Graph_Rev[b].append((a, c))
def Dij(G, D):
    q = []
    heapq.heappush(q, (0, X))
    while q: 
        x, y = heapq.heappop(q) 
        if D[y] < x:
            continue
        for i in G[y]:
            cost = x + i[1]
            if cost < D[i[0]]:
                D[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return D
Dis = Dij(Graph, Dis)
Dis_Rev = Dij(Graph_Rev, Dis_Rev)
Ans = []
for i in range(1, N + 1):
    a = Dis[i] + Dis_Rev[i]
    Ans.append(a)
print(max(Ans))
