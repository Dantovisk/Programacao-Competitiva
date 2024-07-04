#include <bits/stdc++.h>

using namespace std;

int main(){

    map <int,char> mp;
    int b, elim;

    for(char a = 'A'; a<'D'; a++){
        cin>>b;
        if (mp.find(b)!=mp.end() || elim==b){
            elim=b;
            mp.erase(b);
        }else{
            mp[b]=a;
        }
    }
    if(mp.empty()) cout<<"*";
    else{
        auto ptr = mp.begin();
        cout << ptr->second << endl;
    }

    return 0;
}