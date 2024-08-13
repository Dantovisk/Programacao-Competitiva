//dessa vez o objetivo é minimizar o peso para um dado valor
#include <bits/stdc++.h>

using namespace std;

const long long int inf = 1e9+4;

int v[110], w[110], dp[100010];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin>>w[i]>>v[i];
    }

    for (int i=1; i<100002; i++){
        dp[i]=inf;
    }

    for(int i=0; i<n; i++){ //iterando pelos itens
        for(int j=m; j>0; j--){     //iterando pelos valores possiveis
            if(j-w[i]>=0){
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
    }

    cout<<dp[m];
    return 0;
}