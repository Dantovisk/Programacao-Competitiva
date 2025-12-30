#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int MAXN = 2e5+7;

ll tree[MAXN*4];
int v[MAXN];
ll lazy[MAXN*4];
ll passo[MAXN * 4];
 
void build(int no, int l, int r){
    if(l==r){
        tree[no] = 0;
        return;
    }
 
    int mid = (l+r)/2;
 
    build(2*no, l, mid);
    build(2*no + 1, mid+1, r);
 
    tree[no] = tree[no*2] + tree[2*no + 1];
}
 
void unlazy(int no, int l, int r){
    //o no pai usara a soma da pa para obter seu valor
    if(lazy[no]==0) return;
 
    tree[no] += (((2LL*lazy[no] + passo[no]*(r-l)) * (1LL + r- l ))/2LL);
 
    if(l!=r){
        int mid = (l+r)/2;
        lazy[no*2] += lazy[no];
        lazy[no*2 + 1] += lazy[no] + (ll)(mid-l + 1)*passo[no];
        
        passo[no*2] += passo[no];
        passo[no*2 + 1] += passo[no];
    }
 
    lazy[no] = 0;
    passo[no] = 0;
}
 
ll query(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
 
    if(i>r || j<l) return 0;
    if (i >= l && j <= r) return tree[no];
 
    int mid = (i+j)/2;
    return query(no*2, i, mid, l, r) + query(2*no+1, mid+1, j, l, r);
}
 
void update(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    if(i>r || j<l) return;
 
    if(i>= l && j<=r){
        lazy[no] += (i-l)+1;
        passo[no] ++;
        unlazy(no, i, j);
        return;
    }
 
    int mid = (i+j)/2;
 
    update(no*2, i, mid, l, r);
    update(2*no + 1, mid+1, j, l, r);
 
    tree[no] = tree[no*2] + tree[no*2+1];
}

void solve(){
    int n, q;
    cin>>n>>q;

    vector<pii> v;
    rep(i, 0, q){
        int a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }

    vi resp(n+1, 0);

    for(int i = 0; (1<<i) <= n; i++){
        int diff = (1<<i);
        int n2 = n/diff;
        build(1, 1, n2);

        for(auto[l, r] : v){
            if(l &  ((1<<i)-1)) l+= (1<<i);
            l <<=i;
            r <<=i;

            if(l > r) continue;

            update(1, 1, n2, l/diff, r/diff);
        }
        for(int j = 1; j <= n2; j++){
            resp[j*diff] += query(1, 1, n2, j, j) * diff;
        }
    }

    rep(i, 1, n+1) cout<<resp[i]<<" ";
    cout<<"\n";
    
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}