#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b;
    cin>>n>>b;
    vector <int> arq(n);
    for(int i =0; i<n; i++) cin>>arq[i];
    sort(arq.begin(),arq.end());

    int soma = 0;

    auto ptr1=arq.begin();
    auto ptr2=arq.end(); ptr2--;
    while(ptr1<ptr2){
        if(*ptr1+*ptr2 <=b){   
            ptr1++;
        }
        soma++;
        ptr2--;
    }
    if (ptr1==ptr2) soma++;
    cout<<soma;

    return 0;
}