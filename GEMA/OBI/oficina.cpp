#include <bits/stdc++.h>    //OBI 2023 - Terceira fase
#define MAXN 100010

#define pii pair<long long,long long>
using namespace std;

long long v[MAXN];
long long mec[MAXN];
long long cont[MAXN];

priority_queue <pii, vector<pii>, greater<pii>> pq;

int main() {
    long long n, m;
    cin>>n>>m;
    for(long long i=0; i<n; i++) cin>>v[i];
    for(long long i=0; i<m; i++) cin>>mec[i];

    sort(v, v+n);
    sort(mec, mec + m);

    long long soma = 0;

    for(int i = 0; i < m; i++){
        pq.push({0, i});
    }

    for(int i=n-1; i>=0; i--){
        int c = v[i];
        auto x = pq.top();
        pq.pop();

        long long w = (x.first) * c;
        long long pos = x.second;
        cont[pos]++;

        soma+= w;
        pq.push({cont[pos] * mec[pos], pos});
    }

    cout<<soma;

    return 0;
}