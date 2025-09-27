#include <bits/stdc++.h>

using namespace std;

double eps = 1e-10;

int main(){
    double a = 0, b = 0;

    int n, m;
    cin>>n>>m;

    for(int i =0; i<n; i++){
        double k; cin>>k;
        a+= (k+1.0)/2.0;
    }
    for(int i =0; i<m; i++){
        double k; cin>>k;
        b+= (k+1.0)/2.0;
    }

    double r = a-b;

    if(r>eps){
        cout<<"ALICE\n";
    }else if(r<-eps){
        cout<<"BOB\n";
    }else cout<<"TIED\n";
}