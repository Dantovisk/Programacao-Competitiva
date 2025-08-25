#include <bits/stdc++.h>
#define ll long long
#define MAX 200010

int a[MAX];

using namespace std;

namespace seg {
	ll seg[4*MAX]; // maximo de 0 continuos no intervalo
    ll pref[4*MAX]; // maximo de 0 continuos no prefixo
    ll suf[4*MAX]; // maximo de 0 continuos no sufixo
    ll sum[4*MAX];
    ll lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) {
            seg[p] = sum[p] = pref[p] = suf[p] = v[l];
            return seg[p];
        }

		int m = (l+r)/2;

		build(2*p, l, m); build(2*p+1, m+1, r);

        pref[p] = (sum[2*p] ==m-l+1 ? sum[2*p]+pref[2*p+1] : pref[2*p]);
        suf[p] = (sum[2*p+1] ==r-m ? sum[2*p+1]+suf[2*p] : suf[2*p+1]);
        sum[p] = sum[2*p] + sum[2*p+1];
        seg[p] = max({seg[2*p], seg[2*p+1], pref[2*p+1]+suf[2*p]});
        return seg[p];
	}
	ll build(int n2, int* v2) {
		n = n2, v = v2;
		return build();
	}

	void prop(int p, int l, int r) {
        if(lazy[p] == -1) return;
		seg[p] = lazy[p] * (r-l+1);
        pref[p] = lazy[p] * (r-l+1);
        suf[p] = lazy[p] * (r-l+1);
        sum[p] = lazy[p] * (r-l+1);

		if (l != r) {
            lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
        }
		lazy[p] = -1;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	void update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return;
		}
		if (b < l or r < a) return;
		int m = (l+r)/2;
		
        update(a, b, x, p*2, l, m);
        update(a, b, x, p*2+1, m+1, r);

        pref[p] = (sum[2*p] ==m-l+1 ? sum[2*p]+pref[2*p+1] : pref[2*p]);
        suf[p] = (sum[2*p+1] ==r-m ? sum[2*p+1]+suf[2*p] : suf[2*p+1]);
        sum[p] = sum[2*p] + sum[2*p+1];
        seg[p] = max({seg[2*p], seg[2*p+1], pref[2*p+1]+suf[2*p]});
	}
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, k;
    cin>>n>>q>>k;

    for(int i =0; i<n;i++){
        cin>>a[i];
        a[i] = (a[i] == 1? 0: 1);
    }

    
    if(seg::build(n, a) >= k) cout<<"NAO\n";
    else cout<<"SIM\n";
    // cout<<"Maximo de 0: "<<seg::query(0, n-1)<<"\n";

    for(int i =0; i<q;i++){
        int t, l, r;
        cin>>t>>l>>r;
        if(t==1){
            seg::update(l-1, r-1, 0);
        } else{
            seg::update(l-1, r-1, 1);
        }
        // cout<<"Maximo de 0: "<<seg::query(0, n-1)<<"\n";
        cout<<(seg::query(0, n-1) >= k ? "NAO\n" : "SIM\n");
    }



    return 0;
}