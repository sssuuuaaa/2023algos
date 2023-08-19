#include <iostream>
using namespace std;
#include <map>
#include <vector>

const uint64_t INF = (uint64_t)1E15;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int N, E;
	cin >> N >> E;
	vector<vector<pair<int, uint64_t>>> M(N + 1);
	for (int i = 0; i < E; i++)
	{
		int V, T;
		uint64_t D;
		cin >> V >> T >> D;
		M[V].emplace_back(T, D);
	}

	int S, R;
	cin >> S >> R;

	vector<bool> VS(N + 1);
	multimap<uint64_t, int> Q;
	vector<uint64_t> D(N + 1, INF);

	D[S] = 0;
	Q.emplace(0, S);
	while (Q.size())
	{
		int C = begin(Q)->second;
		Q.erase(begin(Q));

		if (VS[C]) continue; else VS[C] = true;
		for (auto& [A, B] : M[C])
		{
			if (D[A] > D[C] + B)
			{
				D[A] = D[C] + B;
				Q.emplace(D[A], A);
			}
		}
	}
	cout << D[R];
	return 0;
}
