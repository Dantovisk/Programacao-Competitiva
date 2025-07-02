#include <bits/stdc++.h>
#define MAXN 100010
#define int long long

using namespace std;

int v1[MAXN];
int v2[MAXN];

int id1[MAXN];
int id2[MAXN];

int pref1[MAXN];
int pref2[MAXN];

//quantos elementos tem entre l e r
int rg(int l, int r){
    return r-l+1;
}

int32_t main(){
    int n, f, s;
    cin>>n>>f>>s;

    for(int i =1; i<=n; i++) {
        cin>>v1[i];
        id1[v1[i]] = i;
        pref1[i] = pref1[i-1] + v1[i];
    }
    for(int i =1; i<=n; i++) {
        cin>>v2[i];
        id2[v2[i]] = i;
        pref2[i] = pref2[i-1] + v2[i];
    }
    int minresp = 1e16+69;


    int l=1, r=1, ant=-10, respl =0, respr0, l2 = id2[v1[1]], r2=1;
    for(int i =1; i<=n; i++) {
        int resa = 0;
        int resb = 0;
        //o atual fecha sequencia
        if(i>1 && id2[v1[i]] == id2[v1[i-1]] + 1){
            //continua a sequencia
            r = i;
            r2 = id2[v1[i]];
        } else{
            //resetou
            r =i;
            l = i;
            l2 = r2 = id2[v1[i]];
        }
        if(l > 1){
            resa += rg(1, l-1) * f;
        }
        if(l2 > 1){
            resa += rg(1, l2-1) * f;
        }

        if(r < n){
            resb += s * rg(r+1, n);
        }
        if(r2 < n){
            resb += s * rg(r2+1, n);
        }
        minresp = min(max(resa, resb), minresp);
    }

    cout<<minresp<<"\n";

}