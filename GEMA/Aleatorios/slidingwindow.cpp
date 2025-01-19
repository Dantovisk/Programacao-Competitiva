#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> val(n);

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    vector<int> analise(val.begin(), val.begin() + k);

    sort(analise.begin(), analise.end());

    auto print_median = [&](vector<int>& v, int k) {
        if (k % 2 == 1) {
            cout << v[k / 2] << " ";
        } else {
            cout << v[k / 2 - 1] << " ";
        }
    };

    print_median(analise, k);

    for (int i = k; i < n; i++) {
        auto ptr2 = lower_bound(analise.begin(), analise.end(), val[i - k]);
        analise.erase(ptr2);

        auto ptr = lower_bound(analise.begin(), analise.end(), val[i]);
        analise.insert(ptr, val[i]);

        print_median(analise, k);
    }
    return 0;
}