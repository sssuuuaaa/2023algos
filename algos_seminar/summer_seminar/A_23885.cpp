#include <iostream>

using namespace std;

int state(int x, int y)
{
  if(x%2==0){
    if(y%2==0)
      return 1;
    else
      return 2;
  }
  else {
    if(y%2!=0)
      return 1;
    else
      return 2;
  }
}

int main()
{
  int n,m;
  int sx,sy,ex,ey;
  cin >> n >> m;
  cin >> sx >> sy;
  cin >> ex >> ey;
  if((m != 1) && (n != 1) && state(sx,sy)==state(ex,ey))
    cout << "YES\n";
  else if ((sx == ex) && (sy == ey))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
