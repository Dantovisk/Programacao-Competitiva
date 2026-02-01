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

typedef double T; // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

const T eps = 1e-15;

T best = 0;
int n;
vvd A;
vd B, C;
double p, q;

double bb(T k){
    T l = 0, r = 1e18;
    T cbest = 0;

    while(r - l > eps){
        T mid = (l+r)/2.0;
        bool mog = false;
        rep(i, 0, n){
            T cur = k * A[i][0] + mid*A[i][1];
            if(cur > 1.0){
                mog = true;
                break;
            }

        }
        if(mog){
            r = mid;
        }
        else{
            l = mid;
            cbest = max(cbest, k * p + mid*q );
        }

    }
    best = max(best, cbest);

    return cbest;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;

    cin>>p>>q;

    A.resize(n, vd(2));

    vd x;

    rep(i, 0, n){
        cin>>A[i][0]>>A[i][1];
    }

    B.resize(n, 1.0);
    C.resize(2, 1.0);
    C[0] = p;
    C[1] = q;

    cout<<fixed<<setprecision(12);

    double l= 0, r = 1e18;

    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = bb(m1);      //evaluates the function at m1
        double f2 = bb(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }

    cout<<best<<"\n";

}