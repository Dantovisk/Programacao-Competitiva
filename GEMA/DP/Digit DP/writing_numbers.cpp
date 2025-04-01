#include <bits/stdc++.h> //CSES - Writing numbers
#define int long long

using namespace std;

vector <int> digits;

//contagem de '1's até o numero n
// dp[id][sum][tight]
int dp[20][20][2];

int dg(int id, int sum, int tight){
    if(id >= (int)digits.size()) return sum;
    if(dp[id][sum][tight] != -1) return dp[id][sum][tight];

    int lim = tight? digits[id]: 9;
    int res = 0;
    for(int j=0; j<=lim; j++){
        res += dg(id+1, sum + (j == 1? 1 : 0), tight && (lim == j));
    }

    return dp[id][sum][tight] = res;
}

int solve(int a){
    if(a < 0) return 0;
    digits.clear();
    memset(dp, -1, sizeof(dp));
    while(a > 0){
        digits.push_back(a%10);
        a/=10;
    }
    reverse(digits.begin(), digits.end());
    
    return dg(0, 0, 1);
}

int32_t main(){
    int n; cin>>n;

    int l = 0, r = 1e18;
    while(l<r){
        int mid = (r/2) + (l/2);

        if(solve(mid) <= n){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    cout<<l - 1;
        
    return 0;
}