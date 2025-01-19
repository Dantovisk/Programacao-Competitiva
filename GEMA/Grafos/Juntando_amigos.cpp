#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> adj(100010);
int visited[100010];
int times[100010];
queue <int> q;

int main() {

    int n, m;
    cin>>n>>m;

    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k=1;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = 1;
            times[i] = k;

            while(!q.empty()){
                int z = q.front();
                q.pop();

                for(int x: adj[z]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = 1;
                        times[x] = k;
                    }
                }
            }

            k++;
        }
        
    }
    
    for(int i=1; i<=n; i++) cout<<times[i]<<" ";

    return 0;
}

