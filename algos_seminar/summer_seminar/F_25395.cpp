#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, S;
vector<int> x;
vector<int> h;
bool visit [1000001];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> S;
    S--;
    x.resize (N);
    h.resize (N);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    for (int i = 0; i < N; i++)
        cin >> h[i];
    queue<int> q;
    q.push (S);
    visit[S] = true;
    int index_st = S;
    int index_fn = S;
    while (index_st - 1 >= 0 && x[index_st - 1] >= x[S] - h[S])
    {
        index_st--;
        q.push (index_st);
        visit[index_st] = true;
    }
    while (index_fn + 1 < N && x[index_fn + 1] <= x[S] + h[S])
    {
        index_fn++;
        q.push (index_fn);
        visit[index_fn] = true;
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (x[cur] - h[cur] <= x[index_st])
        {
            while (index_st - 1 >= 0 && x[index_st - 1] >= x[cur] - h[cur])
            {
                index_st--;
                if (!visit[index_st])
                {
                    q.push (index_st);
                    visit[index_st] = true;
                }
            }
        }
        if (x[cur] + h[cur] >= x[index_fn])
        {
            while (index_fn + 1 < N && x[index_fn + 1] <= x[cur] + h[cur])
            {
                index_fn++;
                if (!visit[index_fn])
                {
                    q.push (index_fn);
                    visit[index_fn] = true;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
        if (visit[i]) cout << i + 1 << " ";
    cout << "\n";
    return 0;
}
