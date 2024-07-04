#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>> n>> k;

    multiset<int> ing;

    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        ing.insert(a);
    }
    for(int i=0; i<k; i++){
        cin>>a;
        auto ptr = ing.upper_bound(a);
        if (ptr == ing.begin()){
            if(*ptr==a) {
                cout<<*ptr<<"\n";
                ing.erase(ptr);
            }
            else cout<<-1<<"\n";
        }
        else{
            ptr--;
            cout<<*ptr<<"\n";
            ing.erase(ptr);
        }
    }
    return 0;
}