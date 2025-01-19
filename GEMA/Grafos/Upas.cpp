#include <bits/stdc++.h>

using namespace std;

int main(){
     srand(time(NULL));
    int n = 63438297;
    int v[100];
    srand(time(NULL));

    for(int i=0; i<100; i++){
        v[i] = rand() % 10000000 + 1;
        cout<<v[i]<<" ";
    } printf("\n");

    for(int i=0; i<100; i++){
        cout<<abs(v[i]-n)<<" ";
    } printf("\n");

    return 0;
}