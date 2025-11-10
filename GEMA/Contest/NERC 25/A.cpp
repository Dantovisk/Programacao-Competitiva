#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin>> n;
    vi v(n);
    set <pii> s;
    rep(i, 0, n){
        cin>>v[i];
        s.insert({v[i], i});
    }

    int cont = 0;

    int l2 = 1;
    for(int i = 0; i<n;){
        while(i < n && (s.find({v[i], i}) == s.end())){
            i++;
            while(i >= l2) l2++;
        }
        while(l2 < n && (s.find({v[l2], l2}) == s.end())){
            l2++;
        }

        if(i >= n) break;

        if(l2 < n && i < n){
            if(v[i] == v[l2]){
                // cout<<"Removi os caras "<<i<<" - "<<l2<<"\n";
                cont++;
                s.erase({v[i], i});
                s.erase({v[l2], l2});
                i = l2+1;
                l2+= 2;
            }
            else{
                auto ptr = s.begin();
                // cout<<"Removi: "<<(*ptr).first<<" "<<(*ptr).second<<"\n";

                cont++;
                s.erase(s.begin());
            }
        }
        else if(i < n){
            auto ptr = s.begin();
            // cout<<"Removi: "<<(*ptr).first<<" "<<(*ptr).second<<"\n";
            cont++;
            s.erase(s.begin());
        }
    }
    cout<<cont<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--){
        solve();
    }
}