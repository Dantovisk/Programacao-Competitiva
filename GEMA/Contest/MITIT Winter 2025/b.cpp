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
    
    priority_queue<pair<int, char>> fila ; 
    
    int x, y, z ; 
    cin >> x >> y >> z ; 
    
    if(x) fila.push({x, 'M'}) ;
    if(z) fila.push({z, 'T'}) ;

    int IT = 0, MI = 0, MT = 0 ; 
    int ctr = 0 ; 
    char resto = '*';

    while(fila.size() && y){
        //cout << fila.size()  << "\n" ;
        auto at = fila.top() ;fila.pop();
        if(at.ss == 'M') MI++ ; 
        else IT++ ; 
        if(at.ff-1 > 0) fila.push({at.ff-1, at.ss}) ;
        y-- ;
    }

    while(fila.size()==2){
        auto at = fila.top() ; fila.pop();
        auto at2 = fila.top() ; fila.pop();
        MT++ ; 
        if(at.ff-1 > 0) fila.push({at.ff-1, at.ss});
        if(at2.ff-1 > 0) fila.push({at2.ff-1, at2.ss}) ;
    }

    if(fila.size() == 1 && fila.top().ff == 1) resto = fila.top().ss ; 
    else if(fila.size() == 1){
        cout << "NO\n" ; return ;
    }

    string ans = "" ;

    while(IT--) {ans += 'I' ; ans += 'T' ;}
    while(MI--){ans += 'M' ; ans += 'I' ;}
    while(MT--){ans += 'M' ; ans += 'T';}

    if(y){
        if((!x|| !z) && y == 1) {
            if(ans.back() == 'I' && ans[0] != 'I'){
                cout << "YES\n";
                cout << 'I' << ans << endl ; 
                return ; 
            }
            else if(ans.back() == 'I' && ans[0] == 'I'){
                cout << "NO\n" ; return ; 
            }
            else if(ans.back() != 'I'){
                cout << "YES\n";
                cout << ans << "I\n";
                return ;
            }
        }
        else{
            cout << "NO\n";
            return ;
        }
    }

    if(resto == '*') {
        cout << "YES\n";
        cout << ans << "\n" ;
    }
    else if(resto == 'T'){
        cout << "YES\n";
        cout << resto ;
        cout << ans << "\n" ;
    }
    else if(resto == 'I'){
        cout << "NO\n" ; 
        return ;
    }
    else{
        cout << "YES\n";
        cout << ans ;
        cout << resto << "\n";
    }


}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;
    while(t--){
        solve();
    }
}