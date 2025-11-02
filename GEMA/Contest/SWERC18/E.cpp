#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; 
    cin>>n;
    
    vector <pair<string, int>> v;
    
    int total = 0;

    int maior = 0;
    int menor = 0;

    rep(i, 0, n){
        string a; int k;
        cin>>a>>k;

        if(k > 0) maior ++;
        if(k < 100) menor ++;

        total += k;
        v.push_back({a, k});
    }
    
    int diff = -10000+total*100;

    if(diff + menor * 49 < 0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    } 
    if(diff - maior * 50 > 0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    } 

    int sobra = min(-diff + min(maior, n-1)*50, 49);
    int falta = max(-diff - min(menor, n-1)*49, -50);
    // cout<<"\n"<<diff<<"\n";
    // cout<<sobra<<" "<<falta<<"\n\n";

    cout<<fixed<<setprecision(2);

    for(auto[s, x] : v){
        float l = x;
        if(!((x == 0 && falta < 0) || (x == 100 && falta > 0))){
            l += (float)falta * 0.01; 
        }
        float r =x;
        if(!((x == 0 && sobra < 0) || (x == 100 && sobra > 0))){
            r += (float)sobra * 0.01; 
        }

        cout<<s<<" "<<l<<" "<<r<<"\n";
    }


}