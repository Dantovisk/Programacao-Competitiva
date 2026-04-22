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

        vi v(n+2, 1), b(n+2, 1);
        rep(i,1, n+1) cin>>v[i];

        // int gcd = v[0];
        // rep(i, 0, n-1) gcd = __gcd(v[i], v[i+1]);


        rep(i, 1, n+1) cin>>b[i];

        int ct = 0;
        rep(i, 1, n+1){
            // if(b[i] % gcd == 0 && b[i] / gcd > 1){
            //     ct++;
            // }
            int l = b[i] / (__gcd(b[i-1], b[i]));
            int r = b[i] / (__gcd(b[i+1], b[i]));
            // cout<<i<<" -: ";
            // cout<<l<<" "<<r<<"\n";
            if(__gcd(l, r) > 1) ct++;
        }

        cout<<ct<<"\n";


    }

    int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);

        int t = 1; 
        cin>>t;

        while(t--)solve();
    }