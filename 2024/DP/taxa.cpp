#include <bits/stdc++.h>

using namespace std;

const long long int inf = 1e6 + 9;

int prefix [410];
int dp[210][410];
int v [410];
int n;
float taxa;

int main(){
    cin >> n >> taxa;

    for(int i=0; i<n; i++){
        cin>>v[i];
        v[i+n] = v[i];  //vetor duplicado para circularidade
    }
    
    prefix[0] = v[0];
    for(int i=0; i<2*n; i++){
        prefix[i] = prefix[i-1] + v[i];
    }

    for(int s=2; s<n; s++){
        for(int i=0; i<n; i++){
            dp[i][s] = inf;
            for(int k = i+1; k< i-s; k++){
                
            }
        }
    }

    return 0;
}