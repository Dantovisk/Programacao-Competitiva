#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ordered_set<int> os;

    set<int> exists;  // para evitar duplicatas

    for (int i = 0; i < n; ++i) {
        char op;
        int x;
        cin >> op >> x;

        if (op == 'I') {
            if (!exists.count(x)) {
                os.insert(x);
                exists.insert(x);
            }
        } else if (op == 'D') {
            if (exists.count(x)) {
                os.erase(x);
                exists.erase(x);
            }
        } else if (op == 'K') {
            if (x <= 0 || x > (int)os.size()) {
                cout << "invalid\n";
            } else {
                cout << *os.find_by_order(x - 1) << "\n";  // 0-based
            }
        } else if (op == 'C') {
            cout << os.order_of_key(x) << "\n";  // número de elementos < x
        }
    }

    return 0;
}
