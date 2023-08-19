#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int main(void)
{	
	int N, M;
	std::cin >> N >> M;
	vector<vector<pair<int, int>>> input;
	input.resize(N);
	for (int i = 0; i < N; i++)
	{
		input[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			int k;
			std::cin >> k;
			input[i][j] = { k,j };
		}
	}
	int t_cnt = 0;
	int t_flag = 0;
	for (int i = 0; i < N; i++)
	{
		sort(input[i].begin(), input[i].end());
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M -1; j++)
		{
			if (input[i][j].first == input[i][j + 1].first)
			{
				input[i][j + 1].second = input[i][j].second;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			t_flag = 0;
			for (int k = 0; k < M; k++)
			{
				if (input[i][k].second != input[j][k].second)
				{
					t_flag = 1;
					break;
				}
			}
			if (t_flag == 0)
			{
				t_cnt++;
			}
		}
	}
	printf("%d", t_cnt);

	return 0;
}
