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

const int MAX = 1e5+7;
const int inf = 1e9+7;

typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() const { return x ^ (ull) b << 21; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

// {start, sz}
pii best = {0, 1};
string sla = "";
HashInterval ha(sla);
string a;

//retorna se x < y
bool test(pii x, pii y){

    auto [ida, sza] = x;
    auto [idb, szb] = y;
    // cout<<a.substr(ida, sza)<<" < "<<a.substr(idb, szb)<<"?\n";

    int s = min(sza, szb);

    int goat = 0;
    int l = 1, r = s+1;
    while(l < r){
        int mid = (l+r)/2;
        // cout<<"deu "<<mid<<"?\n";
        if(ha.hashInterval(ida, ida+mid) == ha.hashInterval(idb, idb+mid)){
            goat = mid;
            l = mid+1;
            // cout<<"hell yeah\n";
        }
        else{
            r = mid;
            // cout<<"hell no\n";
        }
    }

    // cout<<goat<<" chars iguais\n";

    if(s == goat){
        return sza == s;
    }
    return (a[ida+goat] < a[idb+goat]);
}

void solve(){
    int n, l, k; 
    cin>>n>>l>>k;
    cin>>a;

    
    best = {0, l};
    
    if((ll)l*k > (ll)n){
        cout<<"NO\n";
        return;
    }
    if(k == 1){
        cout<<"YES\n"<<a<<"\n";
        return;
    }

    ha = HashInterval(a);

    rep(i, 0, n-l+1){
        int foi = min(i/l, k-1);
        if(foi == 0 and i != 0) continue;

        int r = n-1 - (k-1-foi)*l;
        // cout<<"testando ["<<i<<", "<<r<<"]\n";
        if(r-i+1 < l) continue;

        if(test(best, make_pair(i, r-i+1))){
            best = make_pair(i, r-i+1);
            // cout<<"best virou "<<a.substr(i, r-i+1)<<"\n";
        }
    }

    cout<<"YES\n";
    cout<<a.substr(best.ff, best.ss)<<"\n";
}

#include <sys/time.h>
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}