#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define tii tuple<ll, int, ll>

const int MAX = 6e5+ 15;
const ll mod  = 1e9+7;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<tuple<int,int,int>> v;

//decompoe as queries em potencias de 2
void add(int l, int r, int l2){
    int u = r-l+1;
    for (int i = 20; i>=0; i--){
        if((1<<i) & u){
            v.push_back({i, l, l2});
            l += (1<<i);
            l2 += (1<<i);
        }
    }
}
int vis[MAX], um[MAX], zero[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    string a, aux; cin>>a;
    aux = a;
    reverse(all(aux));
    aux += a;

    UF uf = UF(21*MAX); // Mantem quais indices devem ser iguais

    for(int i =0; i<m; i++){
        int l, r;
        cin>>l>>r;
        l--; r--;

        int l2 = (2*n-1) - r;
        int r2 = (2*n-1) - l;

        add(l, r, l2);
    }

    sort(all(v));

    deque <tuple<int,int,int>> q;

    for(auto k: v) q.push_back(k);

    while(!q.empty()){
        auto [sz, l, l2] = q.front();
        q.pop_front();
        int a = sz*MAX + l;
        int b = sz*MAX + l2;

        a = uf.find(a);
        b = uf.find(b);
        
        if(a == b) continue;
        uf.join(a, b);
        if(sz>0){
            q.push_front({sz-1, l, l2});
            q.push_front({sz-1, l + (1<<(sz-1)), l2 + (1<<(sz-1))});
        }
    }
    for(int i =0; i<n; i++) uf.join(i, (2*n-1)-i);

    for(int i =0; i<n; i++){
        int u = uf.find(i);
        // cout<<u<<" ";
        vis[u] = 1;
        if(a[i] == '1') um[u] =1;
        else if(a[i] == '0') zero[u] = 1; 
    }


    int res = 0;
    for(int i =0; i<2*n; i++){
        // cout<<i<<" : "<<vis[i]<<" "<<um[i]<<" "<<zero[i]<<"\n";
        if(!vis[i]) continue;
        if(um[i] && zero[i]){
            cout<<"0\n";
            return 0;
        }
        if(!(um[i] || zero[i])){
            res ++;
        }
    }

    int resp = 1;
    while(res > 0){
        res--;
        resp <<= 1;
        resp %= mod;
    }
    cout<<resp<<"\n";

    return 0;
}