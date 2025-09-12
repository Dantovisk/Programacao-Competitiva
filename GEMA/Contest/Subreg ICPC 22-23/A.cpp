#include <bits/stdc++.h>


using namespace std;

int main(){
    int n; cin>>n;
    string a; cin>>a;

    char l = 'u';
    int cont = 0;
    int x = 0;
    for(int i =0; i< n; i++){
        if(l == 'a' && a[i] == 'a'){
            cont++;
            cont += x;
            x = 0;
        }
        else {
            l = a[i];
            if(a[i] == 'a') x = 1;
            else x = 0;
        }
    }
    cout<< cont<<"\n";


    return 0;
}