#include <bits/stdc++.h> // Problema Interativo  que usa conceito de aleatoriedade
#define int long long // 2022 Benelux Algorithm Programming Contest (BAPC 22) - J. Jagged Skyline

using namespace std;

int32_t main(){
    int n, h;
    cin>>n>>h;

    int maxh = 0;
    int bestw = 1;

    vector<int> v(n);
    for(int i =0; i<n; i++) v[i] = i+1;

    random_device rd;
    mt19937 g(rd());

    // Embaralha o vetor
    shuffle(v.begin(), v.end(), g);

    for(auto a : v){
        cout<<"? "<< a << " " << maxh + 1<< endl;

        string qual;
        cin>> qual;

        if(qual == "sky") continue;

        maxh ++;
        bestw = a;

        int r = h+1; 
        int l = maxh;
        if(maxh >= h) break;

        while(l < r){
            int mid = (l+r)/2;
            cout<<"? "<< a << " " << mid<< endl;

            cin>> qual;
            if(qual == "sky") r = mid;

            else{
                maxh = mid;
                l = mid + 1;
            }
        }
        if(maxh >= h) break;
    }

    cout<<"! "<<bestw<<" "<<maxh<<endl;

    return 0;
}