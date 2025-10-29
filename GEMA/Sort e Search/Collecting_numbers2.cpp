#include <bits/stdc++.h> 
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

const int MAX = 2e5+5;
int v[MAX], pos[MAX];

int calc(int a, int b){
    // cout<<v[a]<<" "<<v[b]<<"\n";
    int diff = 0;
    int i = v[a];
    if(pos[i] > pos[i+1]) {
        diff--;
    }
    if(pos[i-1] > pos[i]) {
        diff--;
    }

    i = v[b];
    if(i+1 != v[a] && pos[i] > pos[i+1]) {
        diff--;
    }
    if(i-1 != v[a] &&  pos[i-1] > pos[i]) {
        diff--;
    }
    // cout<<diff<<"\n";
    return diff;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q; cin >> n >> q;
    rep(i, 0, n) {
        cin>>v[i];
        pos[v[i]] = i;
    }

    int cont  = 1;
    pos[0] = -1; pos[n+1] = n+1;

    rep(i, 1, n) {
        if(pos[i] > pos[i+1]) cont++;
    }
    // cout<<cont<<"\n\n";

    rep(u, 0, q){
        int a, b;
        cin>>a>>b;
        a--; b--;

        int k = calc(a, b);

        swap(v[a], v[b]);
        swap(pos[v[a]], pos[v[b]]);

        k -= calc(a, b);
        
        cont += k;
        cout<<cont<<"\n";
    }

}