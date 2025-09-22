#include <bits/stdc++.h>

using namespace std;

// Fenwick Tree
struct FT {
	vector<int> sum;
	FT(int n) : sum(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sum.size(); pos |= pos + 1) sum[pos] += dif;
	}
	int query(int pos) { // soma de valores em [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += sum[pos-1];
		return res;
	}
};

int main(){
    int n;
    cin>>n;

    vector <pair<int,int>> corridas;

    for(int i =0; i<n; i++){
        int m; cin>>m;

        vector <int> vis;
        int cont = 0;

        //Coeficiente angular, inicio, final
        vector<tuple<int,int,int>> caras;

        for(int j = 0; j<m; j++){
            int s, e;
            cin>>s>>e;
            
            caras.push_back({e-s, s, e});
            vis.push_back(s);
            vis.push_back(e);
        }
        
        sort(caras.begin(), caras.end());

        sort(vis.begin(), vis.end());
        vis.erase(unique(vis.begin(), vis.end()), vis.end());

        auto id = [&](int coord){
            return (lower_bound(vis.begin(),vis.end(),coord) - vis.begin());
        };

        int k = vis.size();
        FT antes = FT(k), depois = FT(k);

        for(auto [slope, st, ed] : caras){
            int a = antes.query(k) - antes.query(id(st));
            int b = depois.query(k) - depois.query(id(ed));
            
            cont += a-b;

            antes.update(id(st), 1);
            depois.update(id(ed), 1);
        }

        corridas.push_back({cont, i});
    }


    sort(corridas.rbegin(), corridas.rend());

    for(auto [sz, id] : corridas){
        cout<<id<<" "<<sz<<"\n";
    }

    return 0;
}