#include <bits/stdc++.h>

using namespace std;

int val[50010];


bool isPossible(int n, int m, int media){
    int ctr = 0;
    if(media==0) return true;
    for (int i =0; i<n; i++){
        ctr+= val[i]/media;
        if(ctr>= m) return true;
    }
    return false;
}

int main(){
    int x; cin>>x;
    int n, m;
    while(x--){
        cin>>n>>m; //n = caixas,  m = criancas
        for(int i =0; i<n; i++){
            cin>>val[i];
        }
        sort(val, val+n);
        reverse(val, val+n);
        int minimo =0, maximo = 1000000000, media = 1;

        while(isPossible(n, m, minimo)){
            media = minimo + (maximo-minimo)/2;
            if(isPossible(n, m, media)){
                minimo = media+1;
            } else{
                maximo = media;
            }
        }
        
        cout<<media<<endl;
    }


    return 0;
}