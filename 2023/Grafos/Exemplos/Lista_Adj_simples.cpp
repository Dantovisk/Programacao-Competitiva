#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 6, m = 5;
    vector<int> L[n + 1]; // A lista de adjacências
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        L[u].push_back(v);
        L[v].push_back(u); // Caso G seja não direcionado
    }
    return 0;
}