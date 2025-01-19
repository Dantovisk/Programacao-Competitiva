#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int> > vec[200010];
vector <int> veck;
int visitado[200010];
int n, m, k, u, v, c;

void dfs(int u, int ind, int maior){
	visitado[u]=1;
	if(ind == k){
		veck.push_back(maior);
	}
	for(int i=0;i<vec[u].size();i++){
		int v=vec[u][i].first;
		if(visitado[v]!=1){
			//mark[u]+=1;
			int ma = max(maior, vec[u][i].second);
			dfs(v, ind+1, ma);
		}
	}
    visitado[u]=0;
}
int main(){
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> u >> v >> c;
		vec[u].push_back({v, c});
		vec[v].push_back({u, c});
	}
	dfs(1, 1, 0);
	sort(veck.begin(), veck.end());
	cout << veck[0] << endl;
}