#include <bits/stdc++.h>
using namespace std;

map <string, vector<string>> adj;
queue <string> q;
map <string, bool> vis;
int n;
string st, ed;

void bfs() {
    vis[st] = true;
    q.push(st);

    while(!q.empty()){
        
    }
}

int main() {
    cin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        vis[a]= false;
        vis[b]= false;
    }

    auto ptr1 = adj.begin();
    auto ptr2 = adj.begin(); ptr2++;

    while(ptr2 != adj.end()){
        adj[ptr1->first].push_back(ptr2->first);
        adj[ptr2->first].push_back(ptr1->first);
        ptr1++;
        ptr2++;
    }

    cin >> st >> ed;
    bfs();

    return 0;
}