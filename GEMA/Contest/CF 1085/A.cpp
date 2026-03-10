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

    int ct = 0, pos = 0;
    rep(i, 0, n){
        if(a[i] == '1') ct++;
    }
    rep(i, 1, n-1){
        if(a[i] == '0'){
            if(a[i-1] == '1' && a[i+1] == '1'){
                pos++;
                a[i] = '1';
            }
        }
    }
    int sub = 0;
    rep(i, 1, n-1){
        if(a[i] == '1'){
            if(a[i-1] == '1' && a[i+1] == '1'){
                sub++;
                a[i] = '0';
            }
        }
    }
    cout<<ct+pos-sub<<" "<<ct+pos<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}