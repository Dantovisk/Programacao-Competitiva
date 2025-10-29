#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n, m;
    cin>>m>>n;

    long long int somaMin = (m*60)/n;
    long long int somaH = somaMin/60;
    somaMin = somaMin%60;
    somaH = (19+somaH)%24;
    printf("%02lld:%02lld\n",somaH,somaMin);

    return 0;
}