//um algoritmo que encontra dentro de um conjunto de numeros, o subconjunto com a maior soma
//complexidade O(n) - Pagina 23

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int array[100000];
    for(int i =0; i<n; i++){
        cin>>array[i];
    }
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout << best << "\n";
}