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

pii sub(pii& a, pii& b){
    return {a.ff-b.ff, a.ss - b.ss};
}

ll cross(pii a, pii b){
    return (ll)a.ff*(ll)b.ss - (ll)a.ss*(ll)b.ff;
}

int side (pii &a, pii &b, pii &c){
    return (cross(sub(b, a), sub(c, a)) > 0 ? 1 : -1);
}

double angle(pii a){ 
    return atan2(a.ss, a.ff); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    vector<pair<pair<int, int>, int>> v;

    int n; cin>>n;

    rep(i, 0, n){
        int a, b, c;
        cin>>a>>b>>c;

        v.push_back({{a, b}, c});
    }

    ll best = 1e18 + 9;

    rep(i, 0, n){
        vector<pair<double, int>> pts;

        deque<int> pos, neg;

        rep(j, 0, n){
            if(i==j) continue;
            pts.push_back({angle(sub(v[j].ff, v[i].ff)), j});
        }
        sort(all(pts));

        if(pts.empty()) continue;
        vector<int> state(pts.size(), 0); // 1 para pos, -1 para neg, 0 para fronteira

        ll curr = 0;
        auto a = v[i].first;
        auto b = v[pts[0].ss].first;

        for(int j = 1; j<pts.size(); j++){
            auto [c, w] = v[pts[j].ss];
            if(side(a, b, c) > 0){
                pos.push_back(j);
                curr += w;
                state [j] = 1;
            }
            else{
                neg.push_back(j);
                curr -= w;
                state[j] = -1;
            }
        }
        best = min(best, abs(curr));


        for(int j = 1; j<pts.size(); j++){
            auto b = v[pts[j].ss].ff;
            int wj = v[pts[j].ss].ss;
            int w_ant = v[pts[j-1].ss].ss;

            curr += state[j] * (-1) * wj; //tira o peso do atual
            state[j] = 0;
            neg.push_back(j-1); //add a fronteira antiga
            state[j-1] = -1;
            curr -= w_ant;

            while(!pos.empty()){
                int u = pos.front();

                if(state[u] == 0){ //fronteira nao conta
                    pos.pop_front();
                    continue;
                }

                if(side(a, b, v[pts[pos.front()].ss].ff) < 0){ //tira os caras negativos do pos
                    neg.push_back(u);
                    curr -= 2LL*v[pts[u].ss].ss;
                    state[u] = -1;
                    pos.pop_front();
                } 
                else break;
            }
            while(!neg.empty()){
                int u = neg.front();

                if(state[u] == 0){ //fronteira nao conta
                    neg.pop_front();
                    continue;
                }

                if(side(a, b, v[pts[neg.front()].ss].ff) > 0){ //tira os caras positivos do neg
                    pos.push_back(u);
                    curr += 2LL*v[pts[u].ss].ss;
                    state[u] = 1;
                    neg.pop_front();
                } 
                else break;
            }
            best = min(best, abs(curr));
        }
    }

    cout<<best<<"\n";


}