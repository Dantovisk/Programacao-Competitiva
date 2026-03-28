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
#define pb push_back

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, p;
    cin>>n>>p;
    vi v(n);

    rep(i, 0, n){
        cin>>v[i];
    }

    vi num(p), inv(p+1);
    vector<string> nomes(p);

    rep(i, 0, p){
        cin>>num[i];
        cin>>nomes[i];
        inv[num[i]] = p-i;
    }


    if(count(all(v), p) > 1){
        cout<<"-1\n";
        return 0;
    }

    list<pii> ls;
    rep(i, 0, n){
        ls.push_back({i, v[i]});
    }

    int curr = 0;
    auto ptr = ls.begin();
    while(ls.size() > 1){
        if((*ptr).ss < inv[curr+1]){
            ptr = ls.erase(ptr);
        } else ptr++;

        if(ls.size() == 1){
            cout<<(*ls.begin()).ff + 1<<"\n";
            cout<< nomes[p-inv[curr+1]]<<"\n";
        }

        if(ptr == ls.end()) ptr = ls.begin();
        curr = (curr+1)%p;
    }
}