#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    int numero;
    set <int> presentes;
    cin>> n;
    for(int i =0; i<n; i++){
        cin >>numero;
        presentes.insert(numero);
    }


    cout<<presentes.size(); 

}