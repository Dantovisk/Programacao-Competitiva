#include <bits/stdc++.h>
#define int long long

using namespace std;

vector <int> digits;
int dp[20][200][2];

int digitdp(int id, int sum, int tight){
    //já lemos todos os digitos
    if(id >= (int)digits.size()) return sum;
    //já calculamos esse subcaso
    if(dp[id][sum][tight] != -1) return dp[id][sum][tight];

    int lim = tight? digits[id] : 9;
    int acc = 0;
    for(int i =0; i<= lim; i++){
        acc += digitdp(id+1, sum+i, tight && (i==lim));
    }

    return dp[id][sum][tight] = acc;
}

int solve(int a){
    if(a <= 0) return 0;
    digits.clear();
    memset(dp, -1, sizeof(dp));
    while(a > 0){
        digits.push_back(a%10);
        a/=10;
    }
    reverse(digits.begin(), digits.end());
    return digitdp(0, 0, 1);
}

int32_t main(){

    int a, b;

    cin>>a>>b;
    while(a != -1 && b!=-1){
        int resp = solve(b) - solve(a-1);
        cout<<resp<<"\n";
        cin>>a>>b;
    }
    

    return 0;
}