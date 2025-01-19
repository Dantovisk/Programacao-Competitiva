#include <bits/stdc++.h> // OBI 3a fase - 2022

using namespace std;
int v[50][50];
int vert[50], hor[50];

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<< 1;
        return 0;
    }
    if(n==2){
        cout<< -1;
        return 0;
    }

    int soma = 0;
    for(int i=0; i<n-1; i++){
        hor[i] = i+1;
        soma +=i+1;
    }
    hor[n-1] = (hor[n-2]*n)-soma;


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<hor[j]+ ((hor[i]-1) * hor[n-1])<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}