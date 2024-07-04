#include <bits/stdc++.h>
using namespace std;

int n, dif;
float media;

main(){

    cin>>n;
    int camelos[n];
    for(int i=0; i<n;i++) {
        cin>>camelos[i];
        media +=camelos[i];
    }
    media = media/n;

    for(int i=0; i<n; i++) {
        dif = media - camelos[i];
        cout<<dif<<"\n";
    }

    return 0;
}