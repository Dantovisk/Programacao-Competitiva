#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> adj(100010);
queue <int> q;
bool visto[100010];

int main(){
    int n, m;
    cin>>n>>m;

    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int times=0;

    for(int i=0; i<n; i++){
        if(!visto[i]){
            times++;
            for(int x: adj[i]) {
                if(!visto[x]) q.push(x);
            }
            visto[i]=true;
            while(q.size()>0){
                visto[q.front()] = true;
                for(int x: adj[q.front()]) {
                    if(!visto[x]) q.push(x);
                }
                q.pop();
            }
        }
    }
    cout<<times;
    return 0;
}