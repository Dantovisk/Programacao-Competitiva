#include <bits/stdc++.h>

using namespace std;

string ordenados = "";
queue<char> fila;
vector<string> nomes(102);

int main() {
    int n;
    cin >> n;

    map<char, vector<char>> adj;
    map<char, int> pesos;

    for (char i = 'a'; i <= 'z'; i++) {
        pesos[i] = 0;
    }
    
    for (char i = 'a'; i <= 'z'; i++) {
        adj[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> nomes[i];
    }

    for (int i = 1; i < n; i++) {
        string &a = nomes[i-1];
        string &b = nomes[i];
        unsigned int j = 0;

        while (j < a.length() && j < b.length() && a[j] == b[j]) {
            j++;
        }
        if (j < a.length() && j < b.length()) {
            char u = a[j];
            char v = b[j];
            adj[u].push_back(v);
            pesos[v]++;

        } else if (a.length() > b.length()) {
            cout << "Impossible";
            return 0;
        }
    }

    // Agora basta fazer um toposort
    for (char i = 'a'; i <= 'z'; i++) {
        if (pesos[i] == 0) {
            fila.push(i);
        }
    }
    
    while (!fila.empty()) {
        char u = fila.front();
        fila.pop();
        ordenados += u;
        
        for (char v : adj[u]) {
            pesos[v]--;
            if (pesos[v] == 0) {
                fila.push(v);
            }
        }
    }

    if (ordenados.length() < 26) {
        cout << "Impossible";
    } else {
        cout << ordenados;
    }
    
    return 0;
}
