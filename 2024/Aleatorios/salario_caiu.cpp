// Codeforces Round 321 - B. Kefa and Company
//exercicio que usa tecnica dos 2 pointers
#include <bits/stdc++.h> 
using namespace std;

vector<pair<int, int>> v(100010); // 1-dinheiro 2-amizade

int main() {
    int n, d;
    long long int maxSum = 0, sum = 0;

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.begin() + n);

    int i = 0, j = 0;

    while (j < n) {
        if (v[j].first - v[i].first >= d) {
            sum -= v[i].second; 
            i++; 
        } else {
            sum += v[j].second; 
            maxSum = max(maxSum, sum); 
            j++; 
        }
    }

    cout << maxSum;
    return 0;
}
