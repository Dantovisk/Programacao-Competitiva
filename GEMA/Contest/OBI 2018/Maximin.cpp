#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){
    int n, l, r;
    cin>>n>>l>>r;

    for(int i =0; i<n; i++){
        int a; cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int maxn = 0;
    for(size_t i = 1; i< v.size(); i++){
        int mid = (v[i]- v[i-1])/2;
        int id = (v[i] + v[i-1])/2;
        if(id > r || id < l) continue;
        maxn = max(maxn, mid);
    }

    if(l < v[0]) maxn = max(maxn, (v[0] - l));
    if(r > v[n-1]) maxn = max(maxn, (r - v[n-1]));

    if(l > v[0] && l < v[n-1]){
        auto ptr = lower_bound(v.begin(), v.end(), l);
        auto ptr2 = ptr; ptr2--;
        int k = min((*ptr - l), (l - *ptr2));
        maxn = max(maxn, k);
    }
    if(r > v[0] && r < v[n-1]){
        auto ptr = lower_bound(v.begin(), v.end(), r);
        auto ptr2 = ptr; ptr2--;
        int k = min((*ptr - r), (r - *ptr2));
        maxn = max(maxn, k);
    }

    cout<<maxn<<endl;

    return 0;
}