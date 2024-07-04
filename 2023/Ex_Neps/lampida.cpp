#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d, total=0;
    cin>>a>>b>>c>>d;
    if(b!=d){
        total++;
        if(a==c) total++;
    }
    else{
        if(a!=c) total++;
    }

    cout<<total;

    return 0;
}