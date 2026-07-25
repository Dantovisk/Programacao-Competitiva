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
typedef tuple<int, string> tp;
typedef tuple<int, string, int> tpp;

const int maxn = 2e5+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, d; 
    cin>>n>>d;

    // {start, nome cidade, combustivel em km}
    vector <tpp> v;

    priority_queue<tpp, vector<tpp>, greater<tpp>> pq;

    rep(i, 0, n){
        string name;
        int st, comb;
        cin>>name>>st>>comb;
        
        v.push_back({st, name, comb});
    }
    
    sort(all(v));

    vector<tp> res;
    
    rep(i, 0, n){
        auto [st, name, comb] = v[i];
        
        if(st == 0){
            pq.push({1, name, comb + st});
            if(comb + st >= d) res.push_back({1, name});
            continue;
        }

        while(!pq.empty() and get<2>(pq.top()) < st){
            pq.pop();
        }

        if(pq.empty()){
            continue;
        }

        auto [cost, name2, dist] = pq.top();

        pq.push({cost+1, name2 + "->" + name, comb+st});

        if(comb + st >= d) res.push_back({cost+1, name2 + "->" + name});
    }

    if(res.empty()){
        cout<<"-1\n";
        return 0;
    }

    auto [cost, name] = *min_element(all(res));
    cout<<cost<<"\n";
    cout<<name<<"\n";
}