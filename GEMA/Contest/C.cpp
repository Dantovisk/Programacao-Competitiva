#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector <long long int> a(n);
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    int cont =0, maxcont = 0;
    long long int resp =-1, ant = -1;

    for(int i=0; i<n; i++){
        if(a[i]!=ant) cont =0;
        cont++;
        ant=a[i];
        if(cont>maxcont){
            resp = a[i];
            maxcont = cont;
        }
    }
    cout<<resp<<" "<<maxcont;
    return 0;
}