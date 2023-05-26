#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    if (N % 3 == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }

    return 0;
}
