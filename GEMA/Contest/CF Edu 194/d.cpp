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

void solve(){
    int n;
    cin>>n;

    string a;
    cin>>a;

    char l = '0';
    rep(i, 0, n){
        if(l == a[i] and a[i] == '0'){
            cout<<"-1\n";
            return;
        }
        l = a[i];
    }

    int obr = 0;
    int da1 = 1;
    int ct = 0;
    int i = 0;

    for(; i < n; i++){
        if(a[i] == '+'){
            if(obr == 1) ct++;
            else{
                if(obr == -1){
                    da1 = 0;
                    break;
                }
                ct = 1;
                obr = 1;
            }
        }
        else if(a[i] == '-'){
            if(obr == -1) ct++;
            else{
                if(obr == 1){
                    da1 = 0;
                    break;
                }

                ct = 1;
                obr = -1;
            }
        }
        else {
            if((ct%2) == 0){
                da1 = 0;
                break;
            } 
            obr = 0;
            ct = 0;
        }
    }

    if(da1){
        cout<<"1\n";
        return;
    }

    int da2 = 1;
    obr = 0;
    ct = 0;
    i = 0;
    int usei = 0;

    for(; i < n; i++){
        if(a[i] == '+'){
            if(obr == 1) ct++;
            else{
                if(obr == -1){
                    if(usei and (ct == 2)){
                        da2 = 0;
                        break;
                    }
                    else{
                        usei = 1;
                    }
                }
                ct = 1;
                obr = 1;
            }
        }
        else if(a[i] == '-'){
            if(obr == -1) ct++;
            else{
                if(obr == 1){
                    if(usei and (ct == 2)){
                        da2 = 0;
                        break;
                    }
                    else{
                        usei = 1;
                    }
                }

                ct = 1;
                obr = -1;
            }
        }
        else {
            usei = 0;
            obr = 0;
            ct = 0;
        }
    }

    if(da2){
        cout<<"2\n";
        return;
    }


    cout<<"3\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}