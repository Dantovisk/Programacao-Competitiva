#include <bits/stdc++.h>  // D. The Bakery - CF

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 5e4+7;

int n, m;
int v[MAX];
int dp[MAX][55];

const int inf = 1e9+7;

int diff = 0;
int cnt[MAX];
int currL = 1, currR = 0;

void addL(){
    if(cnt[v[currL]] == 1) diff--;
    cnt[v[currL++]] --;
}

void addR(){
    cnt[v[++currR]] ++;
    if(cnt[v[currR]] == 1) diff++;
}

void subR(){
    if(cnt[v[currR]] == 1) diff--;
    cnt[v[currR--]] --;
}

void subL(){
    cnt[v[--currL]] ++;
    if(cnt[v[currL]] == 1) diff++;
}

void updt(int l, int r){
    while(currR < r) addR();
    while(currL > l) subL();
    while(currL < l) addL();
    while(currR > r) subR();
}

// A ordem importa, escolher o mais a esquerda deixa bem mais lento
void solve(int k, int st, int ed, int l, int r){
    int mid = (st + ed)/2;
    pair <int, int> best = {-inf, -1};

    for(int i = min(r, mid); i >= max(l,1); i--){
        updt(i, mid);

        int cost = diff + dp[i-1][k-1];

        best = max(best, {cost, i});
    }

    dp[mid][k] = best.first;

    if(st==ed) return;
    solve(k, st, mid, l, best.second);
    solve(k, mid+1, ed, best.second, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        cin>>v[i];
        addR();
        dp[i][0] = diff;
    }

    for(int i = 1; i<m; i++){
        solve(i, 1, n, i, n);
    }

    cout<<dp[n][m-1]<<"\n";
}