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

const int maxn = 2e5+4;
const int inf = 1e9+3;

string tira(string &a, char depois, char tira){
    string res = "";

    int foi = 0;
    rep(i, 0, sz(a)){
        if(a[i] == depois){
            foi = 1;
        }
        if(foi and a[i] == tira){
            continue;
        }

        res.push_back(a[i]);
    }

    return res;
}

void solve(){
    string a; cin>>a;

    int qt = 0, volta = 0;
    
    
    int ct13 = 0;
    int ct2 = 0;
    rep(i, 0, sz(a)){
        if(a[i] == '4'){
            qt++;
        }
        else if(a[i] == '1' or a[i] == '3') ct13++;
        else{
            ct2++;
            if(i == sz(a)-1 or a[i+1] != '2'){
                //apago 1 e 3
                if(ct13 - volta < ct2){
                    qt += ct13 - volta;
                    volta = 0;
                    ct13 = 0;
                    ct2 = 0;
                }
                //apago 2
                else{
                    qt += ct2;
                    volta += ct2;
                    ct2 = 0;
                }
            }
        } 
        
    }
    
    if(ct13 - volta < ct2){
        qt += ct13 - volta;
        volta = 0;
        ct13 = 0;
        ct2 = 0;
    }
    else{
        qt += ct2;
        volta += ct2;
        ct2 = 0;
        ct13 = 0;
    }
    
    // int res = 10000000;
    // string b = tira(a, '1', '2');
    // b = tira(b, '3', '2');
    // res = min(res, sz(a) - sz(b));

    // b = a;
    // reverse(all(b));
    // b = tira(b, '2', '3');
    // b = tira(b, '2', '1');
    // res = min(res, sz(a) - sz(b));

    // b = a;
    // b = tira(b, '3', '2');
    // reverse(all(b));
    // b = tira(b, '2', '1');
    // res = min(res, sz(a) - sz(b));

    // b = a;
    // b = tira(b, '1', '2');
    // reverse(all(b));
    // b = tira(b, '2', '3');
    // res = min(res, sz(a) - sz(b));

    cout<< qt<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}