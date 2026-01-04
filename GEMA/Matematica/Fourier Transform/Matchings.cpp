#include <bits/stdc++.h> //Kattis - Matchings
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    //esse é o menorzinho, que queremos procurar
    int w2, h2;
    cin>>w2>>h2;

    vector<vi> b(h2, vi(w2));
    rep(i, 0, h2) {
        rep(j, 0, w2) cin>>b[i][j];
    }

    //esse é o texto inteiro
    int w1, h1;
    cin>>w1>>h1;

    vector<vi> a(h1, vi(w1));
    rep(i, 0, h1) {
        rep(j, 0, w1) cin>>a[i][j];
    }

    vd v1(h1*w1), v2(h2*w1);

    rep(i, 0, h1)
        rep(j, 0, w1)
            v1[i*w1 + j] = a[i][j];

    rep(i, 0, h2)
        rep(j, 0, w2)
            v2[i*w1 + j] = b[i][j];

    reverse(all(v2));

    int off = h2*w1-1;
    vd res = conv(v1, v2);

    rep(i, 0, sz(v1)) v1[i] = (v1[i] == 1? 0: 1);
    rep(i, 0, sz(v2)) v2[i] = 0;

    rep(i, 0, h2)
        rep(j, 0, w2)
            v2[i*w1 + j] = (b[i][j] == 1 ? 0 : 1);

    reverse(all(v2));


    vd res2 = conv(v1, v2);

    // for(int i = 0; i<= h1-h2; i++){
    //     for(int j = 0; j<= w1-w2; j++){
    //         cout<<"ovlp0["<<i<<"]["<<j<<"] = "<<(int)(0.49 + res2[i*w1+j + off])<<"\n";
    //     }
    // }

    rep(i, 0, sz(res)) res[i] += res2[i];

    int mx = -1;
    

    vector<pii> caras;

    for(int j = 0; j<= w1-w2; j++){
        for(int i = 0; i<= h1-h2; i++){ 
            int curr = (int)(0.49 + res[i*w1+j + off]);

            if(curr > mx){
                caras.clear();
                mx = curr;
                caras.push_back({i, j});
            }else if(curr == mx){
                caras.push_back({i, j});
            }
        }
    }

    for(auto [y, x] : caras) cout<<x<<" "<<y<<"\n";
}