#include <bits/stdc++.h>

using namespace std;

int main(){
    int q; cin>>q;

    while(q--){
        int n; cin>>n;

        vector <float> v (n);
        float sum1 = 0, sum2 =0;
        int cont = 0;
        for(int i =0; i<n; i++) {
            cin>>v[i];
            sum1 += v[i];
        }
        sort(v.rbegin(), v.rend());

        for(int i =0; sum1 - sum2 > 0.000001 && i < n; i++){
            sum2 += v[i];
            sum1 -= v[i];

            cont++;
        }
        cout<< cont <<"\n";
    }


    return 0;
}