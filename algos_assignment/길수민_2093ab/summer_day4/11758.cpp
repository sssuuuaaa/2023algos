#include <iostream>

using namespace std;

class Point {
public:
    int x;
    int y;
};

class line {
private:
    int x1, x2, y1, y2;
    
public:
	int dx, dy;
    void setLine(Point pt1, Point pt2) {
        x1 = pt1.x;
        x2 = pt2.x;
        y1 = pt1.y;
        y2 = pt2.y;
        dx = x2 - x1;
        dy = y2 - y1;
    }
};

int ccw(line ln1, line ln2) {
    int dx1 = ln1.dx;
    int dx2 = ln2.dx;
    int dy1 = ln1.dy;
    int dy2 = ln2.dy;
    if (dy1 * dx2 > dy2 * dx1) return -1;
    else if (dy1 * dx2 == dy2 * dx1) return 0;
    else return 1;
}

int main()
{
    Point pt1, pt2, pt3;
    cin >> pt1.x >> pt1.y;
    cin >> pt2.x >> pt2.y;
    cin >> pt3.x >> pt3.y;
    line ln1, ln2;
    ln1.setLine(pt1, pt2);
    ln2.setLine(pt2, pt3);
    int result = ccw(ln1, ln2);
    cout << result;
}
