#include <bits/stdc++.h>

using namespace std;

string a, b;
set <int> alfa;
bool resp = true;

int main(){
    int n, k;
    cin>>k>>n;
    cin>>a>>b;

    for(int i=0; i<k; i++){
        alfa.insert(a[i]);
    }
    for(int i=0; i<n; i++){
        if(alfa.find(b[i]) == alfa.end()){
            resp = false;
            break;
        }
    }
    cout<< (resp? "S":"N"); 

    return 0;
}