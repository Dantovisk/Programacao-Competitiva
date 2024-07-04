#include <bits/stdc++.h>  
using namespace std;

int cabecas[20010];
int cavl[20010];

int main(){
    int n, m;
    cin>>n>>m;

    while(n!=0 || m!=0){
        for(int i=0; i<n; i++) cin>>cabecas[i];
        for(int i=0; i<m; i++) cin>>cavl[i];
        sort(cabecas, cabecas+n);
        sort(cavl, cavl+m);

        int j=0, soma=0, cont = 0;
        for(int i=0; i<n; i++){
            while(cavl[j]<cabecas[i]){
                j++;
                if(j>=m) break;
            } 
            soma+=cavl[j];
            j++;
            cont++;
            if(j>=m) break;
        }
        if(cont<n) cout<<"Loowater is doomed!\n";
        else cout<<soma<<endl;
        cin>>n>>m;
    }
    return 0;
}