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

void solve(){
    ll p, q;
    cin>>p>>q;

    if(p>= q){
        cout<<"Alice\n";
        return;
    }
    
    ll qtd = min(p/2LL, q/3LL);
    ll diff1 = p - 2LL*qtd;
    ll diff2 = q - 3LL*qtd;

    // cout<<diff1<<" - "<<diff2<<"\n";
    if(diff2 > diff1){
        cout<<"Alice\n";
        return;
    }

    diff1 -= diff2;


    if(diff1 <= qtd){
        cout<<"Bob\n";
    }else{
        cout<<"Alice\n";

    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}