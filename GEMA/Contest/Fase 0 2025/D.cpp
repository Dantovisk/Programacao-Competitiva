#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    string a, b;
    cin>>a>>b;

    float tot = 0.0;
    float colap = 0.0;

    for(int i =0; i<n; i++){
        if(a[i] == '*' && b[i] != '*'){
            tot++;
            colap++;
        }
        else if(b[i] == '*' && '*' != a[i]){
            tot++;
            colap++;
        }
        else if(b[i] == '*' && a[i] =='*'){
            tot++;
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<colap/tot;


    return 0;
}