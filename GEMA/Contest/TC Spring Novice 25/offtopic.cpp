#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define ff first
#define ss second

int x;

string prt(ll a){
    string res;
    rep(i, 0, x){
        res.pb('0'+(a%2));
        a/=2;
    }
    reverse(all(res));
    return res;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);

    string a; cin>>a;
    cout<<"uai"<<endl;

    ll k = 0;
    ll base = (1<<sz(a));
    x = sz(a);

    for(char c: a){
        k *= 2LL;
        k += c-'0';
    }
    
    while(k > 0){
        k *= 10LL;
        ll c = k / base;
        k %= base;
        cout<<"Dig: "<<prt(c)<<" = "<<c<<"\n";
        cout<<"resto: "<<prt(k)<<"\n";
        cout<<" ---- \n";
    }
    
}