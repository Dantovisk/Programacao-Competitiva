#include <bits/stdc++.h>
using namespace std;
#define N 200010

vector<int> graph[N];   //lista de adjascencias
int vis[N], n, m;       //vis[i] diz se o vétice i foi visitado, n = quant de vértices, n=quant de arestas
void dfs(int x){        //procura em profundidade
	vis[x] = 1;
	for(auto v: graph[x]){
		if(!vis[v])
			dfs(v);
	}
}
int main(){
	cin>>n>>m;
	for(int i = 1,a,b;i<=m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int answer = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){ 
			answer ++;
			dfs(i);
		}
	}

	cout<<answer<<"\n";
}