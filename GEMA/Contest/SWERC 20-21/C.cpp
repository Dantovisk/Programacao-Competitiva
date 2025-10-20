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

const double EPS = 1e-9;


struct UF {
	vi e;
    vector<vi> bateu;
	UF(int n) : e(n, -1), bateu(n, vi(4, 0)){}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        for(int i =0; i<4; i++){
            bateu[a][i] = bateu[a][i] ||  bateu[b][i];
        }
		return true;
	}
    void bate(int u, int id){
        u = find(u);
        bateu[u][id] = 1;
    }

    bool moggou(int u){
        u = find(u);

        if(bateu[u][2] && bateu[u][0]) return true;
        if(bateu[u][1] && bateu[u][3]) return true;
        if(bateu[u][0] && bateu[u][1]) return true;
        if(bateu[u][2] && bateu[u][3]) return true;

        return false;
    }
};

double dist2(pair<double, double>& a, pair<double, double>& b){
    return (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
}
double dist(pair<double, double> a, pair<double, double> b){
    return sqrt(dist2(a, b));
}

double d[1010][1010];
double b[1010][4];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    double X, Y;
    cin>>X>>Y;

    int k; cin>>k;
    vector<pair<double, double>> coord;

    rep(i, 0, k){
        double a, b;
        cin>>a>>b;
        coord.push_back({a, b});
    }

    double l = 0, r = 1e6+1;
    double mid;

    for(int i =0; i<k; i++){
        auto [xa, ya] = coord[i];

        b[i][0] = dist(coord[i], make_pair(xa, Y));
        b[i][1] = dist(coord[i], make_pair(X, ya));
        b[i][2] = dist(coord[i], make_pair(xa, 0));
        b[i][3] = dist(coord[i], make_pair(0, ya));

        // cout<<"b["<<i<<"]: ";
        // rep(fds, 0, 4) cout<<b[i][fds]<<" ";
        // cout<<"\n";

        for(int j = i+1; j<k; j++){
            d[i][j] = dist(coord[i], coord[j]) / 2; 
        }
    }

    while(r-l > EPS){
        UF uf = UF(k);
        mid = (l + r)/2.0;
        // cout<<"Mid = "<<mid<<"\n";

        for(int i =0; i<k; i++){
            auto [xa, ya] = coord[i];
            rep(u, 0, 4)
                if(b[i][u] < mid) uf.bate(i, u);

            for(int j = i+1; j<k; j++){
                if(d[i][j] < mid) uf.join(i, j);
            }
        }

        bool foi = true;
        for(int i =0; i<k; i++){
            if(uf.moggou(i)) {
                foi = false;
                // cout<<"Mogou "<<coord[i].ff<<" "<<coord[i].ss<<"\n";
                break;
            }
        }

        if(foi) l = mid;
        else r = mid;
    }

    cout<<fixed<<setprecision(10);

    cout<<l<<"\n";

}