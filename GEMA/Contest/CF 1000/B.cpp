#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long int 
#define int long long int

using namespace std;

int v[MAXN];
int vl[MAXN];
int vr[MAXN];

int32_t main(){
    int t; cin>>t;

    while(t--){
        int n, l, r;
        cin>>n>>l>>r;

        for(int i=0; i<n; i++){
            cin>>v[i];
            vl[i] = v[i];
            vr[i] = v[i];
        }

        sort(vl, vl + r);
        sort(vr+(l-1), vr + n);

        int siz = r - l + 1;

        int s1 = 0, s2=0;
        for(int i=0; i<siz; i++){
            s1 += vl[i];
        }

        for(int i=l-1; i<l-1+siz; i++){
            s2 += vr[i];
        }

        cout<<min(s1, s2)<<"\n";
    }


    return 0;
}
// 1 1 5 5 5 3 3 3 3 1 1