#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, total;
    int r0, r1, r2, r3 = 8;
    cin>>n;
    total = n*n*n;
    r2 = 12 * (n-2);
    r1 = 6 * (n-2) * (n-2);
    r0 = total - (r1 + r2 + r3);

    cout<<r0<<"\n"<<r1<< "\n"<< r2 << "\n"<< r3<<"\n";

    return 0;
}