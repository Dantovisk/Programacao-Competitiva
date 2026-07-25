#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n; 
    cin>>n;

    long long a=0, b= 0, c=0;

    //calcula os divisíveis
    a = n/3LL;
    b = n/5LL;
    c = n/15LL;

    cout<<a<<" "<<b<<" "<<c<<"\n";
}