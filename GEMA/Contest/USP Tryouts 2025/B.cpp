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

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    vector<pii> queries;
    for(int i =0; i<n; i++){
        int a, b;
        cin>>a>>b;

        queries.push_back({a, b});
    }

    
    vector<pii> q1;
    vector<pii> q2;

    int s1 = ((n+5)/2 < n ? (n+5)/2 : n-(n/2));
    int s2 = n-s1;
    
    for(int i =0; i<s1; i++) q1.push_back(queries[i]);
    for(int i =s1; i<n; i++) q2.push_back(queries[i]);
    
    vector<ll> coord;

    //map<ll, int> id;

    vector<pii> val1;
    //vector<pii> val2;

    ll a1, d1, a2, d2;
    cin>>a1>>d1>>a2>>d2;

    coord.push_back(a1); coord.push_back(d1); 
    coord.push_back(a2); coord.push_back(d2);

    // -----------------------------------------------
    // geração dos subsets
    vector<tii> bitq;
    
    for(int i = 0; i<(1<<s1); i++){
        ll x = 0, y = 0; 
        for(int j =0; j < s1; j++){
            if((1<<j)&i){
                x+=q1[j].ff;
                y+=q1[j].ss;
            }
        }
        coord.push_back(x);
        coord.push_back(y);
        val1.push_back({x, y});
        bitq.push_back({x, 0, y});
    }


    for(int i = 0; i<(1<<s2); i++){
        ll x = 0, y = 0; 
        for(int j =0; j < s2; j++){
            if((1<<j)&i){
                x+=q2[j].ff;
                y+=q2[j].ss;
            }
        }

        ll x1 = a1 - x - 1, y1 = d1 - y;
        ll x2 = a2 - x, y2 = d2 - y + 1;

        coord.push_back(x1); coord.push_back(x2);
        coord.push_back(y1); coord.push_back(y2);

        bitq.push_back({x1, 1, y1});
        bitq.push_back({x2, 1, y2});

        bitq.push_back({x2, 2, y1});
        bitq.push_back({x1, 2, y2});
    }


    // -----------------------------------------------

    sort(all(coord));
    coord.erase(unique(all(coord)), coord.end());

    auto id = [&](ll x){
        return int(lower_bound(all(coord), x) - coord.begin()) + 1;
    };

    vector<tuple<int,int,int>> bitq2;


    FT bit = FT(coord.size()+3);


    ll res = 0;

    for(auto [x, t, y] : bitq){
        x = id(x);
        y = id(y);

        bitq2.push_back({x, t, y});
    }

    sort(bitq2.begin(), bitq2.end());

    for(auto [x, t, y] : bitq2){

        if(t== 0){ //adiciona ponto
            bit.update(y, 1);
        }else if(t==1){ //soma
            res += bit.query(y);
        }else{ //subtrai
            res -= bit.query(y);
        }
    }

    cout<<res<<"\n";
}