#include <bits/stdc++.h>

using namespace std;

string a, b;
bool reau = false;

int main(){
    int n; cin>>n;
    
    //queremos o aumento mais à esquerda
    //ou a diminuição mais à direita

    for(int i=0; i<n; i++){
        char c; cin>>c;
        a.push_back(c);
        b.push_back(c);
        if(c == '5') reau = true;
    }

    if(!reau){
        cout<< -1;
        return 0;
    }

    bool foi = true;
    for(int i=0; i<n-1; i++){
        if(a[i] == '5' || a[i] == '0'){
            swap(a[i], a[n-1]);

            //comparação lexicografica
            if(a > b || foi){
                foi = false;
                b = a;
            }

            swap(a[i], a[n-1]);
        }
    }

    for(auto x: b) cout<<x<<" ";

    return 0;
}