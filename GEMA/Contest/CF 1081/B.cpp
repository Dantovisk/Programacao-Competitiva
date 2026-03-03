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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n; 
    cin>>n;

    string a; cin>>a;

    int ct1 = 0, ct0 = 0;
    rep(i, 0, n){
        if(a[i] == '1') ct1++;
        else ct0++;
    }


    if(ct0 % 2){
        cout<<ct0<<"\n";
        rep(i, 0, n){
            if(a[i] == '0') cout<<i+1<<" ";
        }
        if(ct0) cout<<"\n";
        return;
    }

    if(ct1 % 2){
        cout<<"-1\n";
        return;
    }
    cout<<ct1<<"\n";
    if(ct1){
        rep(i, 0, n){
            if(a[i] == '1') cout<<i+1<<" ";
        }
        cout<<"\n";
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}