#include<bits/stdc++.h>
using namespace std ; 
#define pii pair<int,int> 
#define pb push_back
#define ll long long 
#define ff first 
#define ss second 
#define vi vector<int> 

const int maxn = 4e5 + 5 ; 
const ll inf = 1e7 + 2 ; 

#define esq (2no)
#define dir ((2no)+1)
#define meio ((i+j)>>1)

 
int m, v[maxn], qtd ; 
vector<int> freq;
map<vector<int>, int> mp ; 

void add(int val, int target){
    freq[val]++ ; 
    if(freq[val] == target) qtd++ ; 
    else if(freq[val] == target+1) qtd-- ; 
}

void rem(int val, int target){
    freq[val]-- ; 
    if(freq[val] + 1 == target) qtd-- ; 
    else if(freq[val] == target) qtd++ ; 
}

void solve(){

    int n, k ; cin >> n >> k ; 

    for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

    if((ll)(k) * (ll)(k) * 2LL >= (ll)n){
        freq.resize(maxn,0);
        int ans = 0 ; 
        for(int q = 1 ; q * k <= n ; q++){//qtd de cada marca
            int jan = q*k ; 
            if(jan > n) break ; 
            bool ok = 0 ; 
            for(int i = 1 ; i < jan ; i++) add(v[i], q) ;
            int i = 1 ;int j = jan ;
            for(; j <= n ; j++, i++){
                add(v[j], q) ; 
                if(qtd == k){
                    ans = k*q ; ok = 1 ; 
                    break ; 
                }
                rem(v[i], q) ; 
            }
            for(; i <= j ; i++) rem(v[i], q) ; 
        }
        cout << ans << "\n" ; 
    }

    else{
        int resp = 0;
        vector<int> dif(k-1,0);
        mp[dif] = 1; 
        for(int i = 1 ; i <= n ; i++){
            if(v[i] == 1){
                for(int j = 0; j < k-1; j++) dif[j]++;
            }else{
                dif[v[i]-2]--;
            }
            if(mp[dif] != 0){
                resp = max(resp, i - mp[dif] + 1);
            }else{
                mp[dif] = i+1;
            }
            
        }
        cout << resp << '\n';
    }

}

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    int t ; t = 1 ; //cin >> t ;

    while(t--) solve(); 

}