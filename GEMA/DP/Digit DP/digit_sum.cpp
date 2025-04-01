#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[index][sum][tight]
// index -> o indice do digito em que estamos
// sum -> a soma dos digitos acumulada até agora
// tight -> indica se estamos limitados ao prefixo de X (0 = nao 1 = sim)
ll dp[20][200][2]; 

vector <int> digits;

ll solve(int ind, ll sum, int tight){
    //já vimos todos os digitos
    if(ind == (int)digits.size()) return sum;

    //já calculamos essa soma
    if(dp[ind][sum][tight] != -1) return dp[ind][sum][tight];

    ll res = 0;

    //se nao estamos limitados
    int limit = tight? digits[ind] : 9;

    //iterando pelos digitos até o limite
    for(int i=0; i<=limit; i++){
        //cout<<ind + 1<<" "<<sum+i<<" "<< endl;
        res += solve(ind+1, sum+i, tight && (i==limit));
    }

    return dp[ind][sum][tight] = res;
}

ll dsum(ll a){
    if(a<=0) return 0;
    digits.clear();
    while(a > 0){
        digits.push_back(a % 10);
        a/=10;
    }
    reverse(digits.begin(), digits.end());

    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 1);
}

int main() {
    int t; cin>>t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << dsum(b) - dsum(a - 1) << "\n";
    }
    return 0;
}
