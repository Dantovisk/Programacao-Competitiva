#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pb push_back
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define len length

const int MAX = 2e5+69;
const int inf = 1e8 + 69;
#define pii pair<int,int>

namespace segmax {
	pair<ll, int> seg[4*MAX];
	int n, *v;

    pair<ll, int> build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l], l};
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	pair<ll, int>  query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {-inf, -1};
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
    void update(int id, int p=1, int l=0, int r=n-1){
        if (l == r) {
            seg[p] = {-inf, id};
            return;
        }
        int m = (l+r)/2;
        if (id <= m) update(id, 2*p, l, m);
        else update(id, 2*p+1, m+1, r);
        seg[p] = max(seg[2*p], seg[2*p+1]);
    }
};

namespace segmin {
	pair<ll, int> seg[4*MAX];
	int n, *v;

	pair<ll, int> build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l], l};
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	pair<ll, int>  query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {inf, -1};
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
    void update(int id, int p=1, int l=0, int r=n-1){
        if (l == r) {
            seg[p] = {inf, id};
            return;
        }
        int m = (l+r)/2;
        if (id <= m) update(id, 2*p, l, m);
        else update(id, 2*p+1, m+1, r);
        seg[p] = min(seg[2*p], seg[2*p+1]);
    }
};

int v[MAX];
int lef[MAX], rig[MAX];
int vis[MAX];

void solve(){
    int n, a, b;
    cin>>n>>a>>b;
    a--;
    b--;

    for(int i =0; i<n; i++) {
        cin>>v[i];
        lef[i] = i-v[i];
        rig[i] = i+v[i];
    }


    segmax::build(n, rig);
    segmin::build(n, lef);

    fill(vis, vis+n+1, 0);


    queue<pii> q;

    q.push({a, 0});
    vis[a] = 1;
    segmin::update(a);
    segmax::update(a);

    while(!q.empty()){
        auto [u, t] = q.front();
        q.pop();

        // cout<<"To no "<<u<<", t = "<<t<<"\n";

        if(u ==  b){
            cout<<t<<"\n";
            return;
        }

        
        int l = max(u - v[u], 0), r = min(u + v[u], n-1);

        //Vê os vertices alcançáveis à esquerda
        auto [reachl, v1] = segmax::query(l, u-1);
        while (reachl >= u)
        {
            vis[v1] = 1;
            q.push({v1, t+1});
            segmin::update(v1);
            segmax::update(v1);

            auto xd = segmax::query(l, u-1);
            reachl = xd.first;
            v1 = xd.second;
        }

        //Vê os vertices alcançáveis à direita
        auto [reachr, v2] = segmin::query(u+1, r);
        while (reachr <= u)
        {
            vis[v2] = 1;
            q.push({v2, t+1});
            segmin::update(v2);
            segmax::update(v2);

            auto xd = segmin::query(u+1, r);
            reachr = xd.first;
            v2 = xd.second;
        }
        
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();
}