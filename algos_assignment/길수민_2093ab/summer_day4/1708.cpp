#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
int N;
vector<pi> pos;
pi firstPos;

int ccw (pi a, pi b, pi c)
{
    a = (pair<long, long>)a;
    b = (pair<long, long>)b;
    c = (pair<long, long>)c;
  //  ll ans = a.first * b.second + b.first * c.second + c.first * a.second;
    //ans -= a.second * b.first + b.second * c.first + c.second * a.first;
    ll ans = a.first * b.second;
    ans -= a.second * b.first;
    ans += b.first * c.second;
    ans -= b.second * c.first;
    ans += c.first * a.second;
    ans -= c.second * a.first;

    if (ans > 0) return 1;
    if (ans == 0) return 0;
    return -1;
}

bool compY (const pi &a, const pi &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

bool compDir (const pi &a, const pi &b)
{
    int dir = ccw (firstPos, a, b);
    if (dir) return dir == 1;
    else return compY (a, b);
}

int convex_hull ()
{
    stack<int> point;
    point.push (0);
    point.push (1);
    pi p1, p2, p3;

    for (int i = 2; i < N; i++)
    {
        p3 = pos[i];
        while (2 <= point.size())
        {
            int tmp = point.top();
            p2 = pos[tmp];
            point.pop();
            p1 = pos[point.top()];
            if (ccw(p1, p2, p3) == 1)
            {
                point.push(tmp);
                break;
            }
        }
        point.push (i);
    }
    return point.size();
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    pos.resize (N);
    for (int i = 0; i < N; i++)
        cin >> pos[i].first >> pos[i].second;
    sort (pos.begin(), pos.end(), compY);
    firstPos = pos[0];
    sort (pos.begin() + 1, pos.end(), compDir);
    cout << convex_hull() << "\n";
    return 0;
}
