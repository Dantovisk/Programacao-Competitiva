#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX  = 2e5+3;
int v[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    rep(i, 0, n) cin>>v[i];

    int l = 0, r = 0;

    int sum = 0;
    int res = 0;
    while(r < n){
        sum += v[r];

        while(sum > k){
            sum -= v[l++];
        }
        if(sum == k) res++;

        r++;
    }
    cout<<res<<"\n";
    
    return 0;
}
