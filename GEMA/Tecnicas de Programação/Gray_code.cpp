#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int gray(int u){
    return u ^ (u>>1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;

    rep(i, 0, (1<<n)){
        int k = gray(i);

        for(int j = n-1; j>= 0; j--){
            cout<<(((1<<j)&k)? 1: 0);
        }
        cout<<"\n";
    }
}