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

const int maxn = 2e5+4;
const int inf = 1e9+3;

/**
 * Author: Ludo Pulles, chilli, Simon Lindholm
 * Date: 2019-01-09
 * License: CC0
 * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf (do read, it's excellent)
   Accuracy bound from http://www.daemonology.net/papers/fft.pdf
 * Description: fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$ for all $k$. N must be a power of 2.
   Useful for convolution:
   \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
   For convolution of complex numbers or more than two vectors: FFT, multiply
   pointwise, divide by n, reverse(start+1, end), FFT back.
   Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$
   (in practice $10^{16}$; higher for random inputs).
   Otherwise, use NTT/FFTMod.
 * Time: O(N \log N) with $N = |A|+|B|$ ($\tilde 1s$ for $N=2^{22}$)
 * Status: somewhat tested
 * Details: An in-depth examination of precision for both FFT and FFTMod can be found
 * here (https://github.com/simonlindholm/fft-precision/blob/master/fft-precision.md)
 */
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

void solve(){
    int n, k; 
    cin>>n>>k;

    int sum = 0;
    vi res;

    string a; cin>>a;

    vd v1(n), v2(n);
    
    rep(i, 0, n){
        v1[i] = (a[i] - '0');
        
        sum += 4 * (a[i] - '0');
    }
    rep(i, 0, n){
        v2[n-1-i] = (a[i] == '0' ? 0 : 1);
    }

    vd cv = conv(v1, v2);
    int adj = 0;
    int basico = 0;
    rep(i, 0, n-1){
        if(a[i] > '0' and a[i+1] > '0'){
            adj += a[i] - '0';
            adj += a[i+1] - '0';
        }
        else{
            basico += a[i] - '0';
            basico += a[i+1] - '0';
        }
    }
    
    //caso w=1 e w=n
    res.push_back(basico);
    if(n > 1) res.push_back(basico);
    int cimabaixo = (a[0]-'0') + (a[n-1]-'0');

    for(int w = 2; w <= n-1; w++){
        // cout<<"w = "<<w<<"\n";
        int aux = 0;
        cimabaixo += (a[w-1] - '0');
        cimabaixo += (a[n-w] - '0');
        
        aux += int(cv[n-1-w] + 0.3);
        aux += int(cv[n-1+w] + 0.3);

        int esqdir = 0;
        

        for(int i = 0; i < n; i += w){
            esqdir += (a[i] - '0');
            if(i > 0 and a[i-1] > '0') esqdir -= (a[i] - '0');
        }

        for(int i = w-1; i < n; i += w){
            esqdir += (a[i] - '0');
            if(i < n-1 and a[i+1] > '0') esqdir -= (a[i] - '0');
        }

        if(n % w){
            esqdir += a[n-1] - '0';
        }
        // cout<<"|x - y| = w -> "<<aux<<"\n";
        // cout<<"adj = "<<adj<<"\n";
        // cout<<"cimabaixo = "<<cimabaixo<<"\n";
        // cout<<"esqdir = "<<esqdir<<"\n\n";
        aux += adj;
        aux += cimabaixo;
        aux += esqdir;

        res.push_back(sum-aux);
    }

    sort(all(res));
    reverse(all(res));

    // for(auto x: res) cout<<x<<" ";
    // cout<<"\n";

    cout<<res[k-1]<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    solve();
}