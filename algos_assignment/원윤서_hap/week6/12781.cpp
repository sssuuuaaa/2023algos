#include <iostream>

using namespace std;

int ax, bx, cx, dx, ay, by, cy, dy;

void solution() {
    int result = 1;

    int a = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
    int b = (bx - ax) * (dy - ay) - (dx - ax) * (by - ay);

    if (!(a < 0 && b > 0) && !(a > 0 && b < 0)) {
        result = 0;
    }

    int c = (cx - dx) * (ay - dy) - (ax - dx) * (cy - dy);
    int d = (cx - dx) * (by - dy) - (bx - dx) * (cy - dy);

    if (!(c < 0 && d > 0) && !(c > 0 && d < 0)) {
        result = 0;
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    solution();

    return 0;
}

# 출처: https://velog.io/@y00913/%EB%B0%B1%EC%A4%80-12781-PIZZA-ALVOLOC
