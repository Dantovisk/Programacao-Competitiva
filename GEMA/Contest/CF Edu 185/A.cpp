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
    int n; cin>>n;
    if(n==1) cout<<"1\n";
    else if(n==2) cout<<"9\n";
    else if(n<5){
        int resp = n*n;
        resp *= 4;
        resp -= (1 + 2 + 1 + n);

        cout<<resp<<"\n";
    } else{
        int resp = n*n;
        resp *= 5;
        resp -= ((1 + 2 + 1 + 1) + (3*n + 2*n));

        cout<<resp<<"\n";
    }
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}