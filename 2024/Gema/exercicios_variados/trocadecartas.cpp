#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set <int> c1, c2;
    int n, k;
    cin>>n>>k;
    int a;
    unsigned int resposta =0;
    for(int i =0; i<n; i++){
        cin>>a;
        c1.insert(a);
    }
    for(int i =0; i<k; i++){
        cin>>a;
        c2.insert(a);
    }
    
    while(c2.size()>0){
        auto ptr= c2.begin();
        if(c1.find(*ptr)==c1.end()){
            resposta++;
        } else c1.erase(*ptr);
        c2.erase(ptr);
    }
    if (resposta<c1.size()) cout<<resposta;
    else cout << c1.size();
    return 0;
}