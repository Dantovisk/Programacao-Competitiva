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
vector<string> grid;
int vis[13][13];
int n; 
int dir [4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

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


map<int, int> nimbers;

int nimber(vector<vi>& gr, int mask){
    // cout<<"mask: "<<mask<<"\n";

    if(nimbers.find(mask) != nimbers.end()) return nimbers[mask];

    set <int> states;
    for(int i = 0; i<gr.size(); i++){
        if(((mask >> i) & 1)) continue;

        int nm =  mask | (1<<i);
        for(auto v: gr[i]){
            nm |= (1<<v);
        }
        states.insert(nimber(gr, nm));
    }

    int mex = 0;
    while(states.find(mex) != states.end()) mex++;

    nimbers[mask] = mex;
    // cout<<"mex = "<<mex<<"\n";

    // cout<<mask<<": "<< mex<<"\n";

    return mex;
}

int grundy(vector<vi>& gr){
    // for(int i =0; i<gr.size(); i++){
    //     for(auto x: gr[i]){
    //         cout<<i<<" -> "<<x<<"\n";
    //     }
    // }
    nimbers.clear();
    return nimber(gr, 0);
}

int lb[1000];

int solve(int xis, int ips){
    queue<pii> q;
    vector<pii> lagos;
    vector<pii> terra;
    set<pii> terraAux;
    map<pii, int> id;

    q.push({xis, ips});
    vis[xis][ips] = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        lagos.push_back({x, y});

        for(auto d: dir){
            int nx = d[0] + x;
            int ny = d[1] + y;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny] || grid[nx][ny] == 'x') continue;
            if(grid[nx][ny] == '*') q.push({nx, ny});
            if(grid[nx][ny] == '.') {
                terra.push_back({nx, ny});
                terraAux.insert({nx, ny});
            }
            vis[nx][ny] = 1;
        }
    }

    int xd = 0;
    for(auto k: terra){
        id[k] = xd++;
    }

    UF uf = UF(xd);

    map <int, vi> paias;

    // cout<<"TERRA:\n";
    for(auto [x,y] : terra){
        // cout<<x<<" "<<y<<"\n";
        for(auto d: dir){
            int nx = d[0] + x;
            int ny = d[1] + y;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if(terraAux.find({nx, ny}) != terraAux.end()){
                uf.join(id[{nx, ny}], id[{x, y}]);
                paias[id[{nx, ny}]].push_back(id[{x, y}]);
            }
        }
    }   

    map <int, vi> compsz;
    for(int i =0; i< terra.size(); i++){
        compsz[uf.find(i)].push_back(i);
    }   

    int xors = 0;

    for(auto [comp, nodes] : compsz){
        vector<vector<int>>gr(nodes.size());
        sort(all(nodes));

        rep(i, 0, nodes.size()){
            lb[nodes[i]] = i; 
        }

        for(auto no: nodes){
            for(auto p : paias[no])
                gr[lb[no]].push_back(lb[p]);
        }

        // cout<<"componente: "<<comp<<"\n";
        xors ^= grundy(gr);
    }
    
    return xors;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    cin>>n;

    grid.resize(n);

    rep(i, 0, n) cin>>grid[i];

    int xorsum = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(vis[i][j]) continue;
            if(grid[i][j] != '*') continue;
            xorsum ^= solve(i, j);
        }
    }

    if(xorsum) cout<<"First player will win\n";
    else cout<<"Second player will win\n";

    return 0;
}