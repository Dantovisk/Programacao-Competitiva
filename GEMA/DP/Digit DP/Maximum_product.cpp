#include <bits/stdc++.h> //ainda ta errado, necessario arrumar
#define int long long int
using namespace std;

int prod(string a){
    int i = 0;
    while(a[i] == '0') i++;

    int resp = 1;
    while(i < (int)a.length()){
        resp *= (a[i] - '0');
        i++;
    }
    return resp;
}


int32_t main(){
    string l, r;
    cin>>l>>r;

    while(l.length() < r.length()) l.insert(l.begin(), '0');

    string resp = "1";

    //id = tamanho do prefixo comum entre r e str
    bool igual = true;
    for(int id = 0; id<= (int)r.length(); id++){
        igual = igual && (l[id] == r[id]); //se os prefixos são iguais
        string a = r.substr(0, id);

        if(igual && id <r.length()) continue;               //nao da pra add 9
        //if(r[id] <= 1) continue;


        if(id < r.length()) a.push_back(char(r[id]-1));
        while(a.length() < r.length()) a.push_back('9');

        if(prod(a) > prod(resp)) resp = a;
    }

    while(resp[0] == '0') resp.erase(resp.begin());

    cout<<resp<<"\n";


    return 0;
}