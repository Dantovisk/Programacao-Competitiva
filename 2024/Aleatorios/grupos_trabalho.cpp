#include <bits/stdc++.h>

using namespace std;

vector <pair<int,int>> like;
vector <pair<int,int>> dislike;
set <int> adj[1000000];

int e, m, d;

int main(){
    cin>>e>>m>>d;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        like.push_back({a,b});
    }
    for(int i=0; i<d; i++){
        int a, b;
        cin>>a>>b;
        dislike.push_back({a,b});
    }
    for(int i=0; i<e/3; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].insert(b);
        adj[a].insert(c);
        adj[b].insert(a);
        adj[b].insert(c);
        adj[c].insert(a);
        adj[c].insert(b);
    }
    int resp = 0;

    for(int i=0; i<m; i++){
        int a = like[i].first;
        int b = like[i].second;
        if(adj[a].find(b)==adj[a].end()) resp++;
    }
    for(int i=0; i<d; i++){
        int a = dislike[i].first;
        int b = dislike[i].second;
        if(adj[a].find(b)!=adj[a].end()) resp++;
    }
    cout<<resp;
    return 0;
}
