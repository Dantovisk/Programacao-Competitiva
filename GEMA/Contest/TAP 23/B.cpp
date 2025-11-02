#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5+7;

int a[MAX], mod[MAX];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    vector <string> v(n);

    rep(i, 0, n){
        cin>>v[i];
    }

    int cont = 0;
    rep(i, 0, n){
        rep(j, 0, n-1){
            if(v[i][j] == 'N' && v[i][j+1] == 'N'){
                cont++; 
                j++;
            }
        }
    }

    cout<<cont<<"\n";
}