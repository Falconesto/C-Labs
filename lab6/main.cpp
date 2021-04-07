#include <iostream>
#include <vector>

using namespace std;

struct elem {
    int value;
    int left;
    int right;
};

void checking(vector<elem> &tree, vector<int> &values, int root) {
    if (root != -1) {
        checking(tree, values, tree[root].left);
        values.push_back(tree[root].value);
        checking(tree, values, tree[root].right);
    }
}

int correct(vector<elem> &tree) {
    vector<int> values;
    checking(tree, values, 0);
    for (int i = 1; i < values.size(); ++i) {
        if (values[i - 1] >= values[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int count;
    cin >> count;
    vector<elem> tree(count);
    for (int i = 0; i < count; ++i) {
        cin >> tree[i].value >> tree[i].left >> tree[i].right;
        tree[i].left--;
        tree[i].right--;
    }
    if (count == 0 || correct(tree)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}