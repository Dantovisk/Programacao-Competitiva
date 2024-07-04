#include <bits/stdc++.h>

using namespace std;

const int INF = 1000010;
const int MAXN = 100010;

int v[MAXN], smpref[MAXN], opt[MAXN];

int main(){
    int n, contagem =1;
    cin>>n;
    int j1, j2;
    while (n>0){
        for(int i=0; i<n; i++){
            cin>>j1>>j2;
            v[i]=j1-j2;
        }
        opt[0]=0;
        smpref[0]=v[0];
        
        for(int i =1; i<n; i++){
            if(v[i]>v[i]+smpref[i-1]){
                opt[i]=i;
            }else{
                opt[i]=opt[i-1];
            }
            smpref[i]= max(v[i],v[i]+smpref[i-1]);
        }
        int indresp=0;
        int resp=-INF;

        for(int i=0; i<n; i++){
            if(resp<=smpref[i]){
                resp = smpref[i];
                indresp=i;
            }
        }
        cout<<"Teste "<<contagem<<endl;
        if(resp>0){
            cout<<opt[indresp]+1<<" "<<indresp+1<<endl;
        }
        else{
            cout<<"nenhum"<<endl;
        }
        cout<<endl;

        contagem++;
        cin>>n;
    }

    return 0;
}