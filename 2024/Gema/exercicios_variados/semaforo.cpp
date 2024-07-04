#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; 
    cin>>k>>n;

    set <int> smf;
    multiset <int> dist;

    int a;
    int maior, menor;
    dist.insert(k);
    smf.insert(0);
    smf.insert(k);

    while(n--){
        cin>>a;
        
        auto ptr = smf.upper_bound(a);
        maior = *ptr;
        ptr--;
        menor = *ptr; 
    
        dist.erase(dist.find(maior-menor));
        dist.insert(maior-a);
        dist.insert(a-menor);
        smf.insert(a);
        
        cout<<*dist.rbegin()<<" ";
    }
    return 0;
}
