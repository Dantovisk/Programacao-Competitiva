// CSES Problem Set - Playlist (task 1141)
// Exercicio que usa tecnica dos 2 pointers
#include <bits/stdc++.h> 
using namespace std;

vector<int> v(200100); 
unordered_map <int, int> vistos;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int i = 0, maxCont = 0;

    for (int j = 0; j < n; j++) {
        vistos[v[j]]++;
        while (vistos[v[j]] > 1) {
            vistos[v[i]]--;
            i++;
        }
        maxCont = max(maxCont, j - i + 1);
    }

    cout << maxCont;
    return 0;
}