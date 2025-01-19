#include <bits/stdc++.h>    //muito divertido, nao?

using namespace std;

int main(){
    int n;
    cin>>n;

    if(n<=1) cout<<0;
    else cout<< (n-2)/2 + (n%2);
}