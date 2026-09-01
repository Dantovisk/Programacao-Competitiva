#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> base;
vector<string> res;
void add(ll a){
    for(auto x: base){
        if((x^a) < a){
            res.push_back(to_string(a) + " ^ " + to_string(x));
            a = min(a, (x^a));
        }
    }
    if(a) base.push_back(a);
}

bool inn(ll a){
    for(auto x: base){
        a = min(a, (x^a));
    }
    return (a == 0);
}
const ll mx = 4e17;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;

    add(n);

    while(!inn(1)){
        int foi = 0;
        for(auto c: base){
            for(auto d: base){
                if(c + d < mx and !inn(c+d)){
                    res.push_back(to_string(c) + " + " + to_string(d));
                    add(c+d);
                    foi = 1;
                    break;
                }
            }
            if(foi) break;
        }
    }
    
    cout<<sz(res)<<"\n";

    for(auto s: res){
        cout<<s<<"\n";
    }
}