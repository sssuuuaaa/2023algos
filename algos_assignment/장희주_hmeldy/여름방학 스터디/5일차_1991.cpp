#include <iostream>
using namespace std;
int tree[27][2];

void preorder(int x) {
    if (x < 0) return;
    cout << char(x + 'A');
    preorder(tree[x][0]);
    preorder(tree[x][1]);
}

void inorder(int x) {
    if (x < 0) return;
    inorder(tree[x][0]);
    cout << char(x + 'A');
    inorder(tree[x][1]);
}

void postorder(int x) {
    if (x < 0) return;
    postorder(tree[x][0]);
    postorder(tree[x][1]);
    cout << char(x + 'A');
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int loop;
    char node, l_node, r_node;

    cin >> loop;
    while (loop--) {
        cin >> node >> l_node >> r_node;
        node = node - 'A'; //0
        if (l_node == '.') {
            tree[node][0] = -1;
        }
        else {
            tree[node][0] = l_node - 'A';
        }

        if (r_node == '.') {
            tree[node][1] = -1;
        }
        else {
            tree[node][1] = r_node - 'A';
        }
    }
    preorder(0); cout << "\n";
    inorder(0); cout << "\n";
    postorder(0);
}
