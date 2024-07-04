#include <bits/stdc++.h>
using namespace std;

unsigned int v[5010], ori[5010];

void find(unsigned int i, unsigned int j, unsigned int k){
    unsigned int r[3] ={};
    while(ori[r[0]]!=i) r[0]++;
    while(ori[r[1]]!=j || r[1]==r[0]) r[1]++;
    while(ori[r[2]]!=k || r[2]==r[0] || r[2]==r[1]) r[2]++;
    sort(r, r+3);
    cout<<r[0]+1<<" "<<r[1]+1<<" "<<r[2] +1;
}

int main(){
    bool xd= false;
    unsigned int n, soma;
    cin>>n>>soma;
    for(unsigned int i =0; i<n; i++){
        cin>>v[i];
        ori[i]=v[i];
    }
    sort(v, v+n);

    unsigned int i=0, j=n-2, k=n-1;

    while(k>1){
        while(j<n){
            if(v[j]+v[i]+v[k]==soma){
                find(v[i],v[j],v[k]);
                k=1;
                xd = true;
                break;
            }
            else if(v[j]+v[i]+v[k]>soma)j--;
            else i++;
            if(i==j) break;
        }
        k--;
        i=0; j=k-1;
    }
    
    if(!xd)cout<<"IMPOSSIBLE";

    return 0;
}