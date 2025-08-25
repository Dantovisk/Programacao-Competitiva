#include <bits/stdc++.h> //Counting Divisors - CSES
#define ll long long

using namespace std;

int divs(int n) {
	vector<int> factors;

    int diff = 0;
    for(int i = 1; i * i <= n; i++){
        if(n%i == 0) factors.push_back(i);
        if(i*i == n) diff++;
    }

    int res = factors.size() - diff;
    for(auto f: factors){
        //cout<<f<<" ";
        if(n % f == 0) res++;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin>>q;

    while(q--){
        int n; cin>>n;

        cout<<divs(n)<<"\n";
    }


    return 0;
}