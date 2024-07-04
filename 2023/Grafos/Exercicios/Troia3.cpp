#include <bits/stdc++.h>

using namespace std;

int n, m, vis[20010]; //lista de visitinhas
vector<int> grafus[20010]; // A lista de adjacências

void dfs(int x){        //procura em profundidade
	vis[x] = 1;
	for(auto v: grafus[x]){
		if(!vis[v])
			dfs(v);
	}
}

int main()
{
    cin>>n>>m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        grafus[u].push_back(v);
        grafus[v].push_back(u); // Caso G seja não direcionado
    }

    int answer = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){ 
			answer ++;
			dfs(i);
		}
	}

	cout<<answer<<"\n";

    return 0;
}