#include <bits/stdc++.h>

using namespace std;


int main(){
    string a, b;
    cin>>a>>b;

    reverse(a.begin(), a.end());

    if(b.find(a) != string::npos){
        cout<<"acompanha";
    } else{
        cout<<"fica em casa";
    }

    return 0;
}