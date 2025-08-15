#include <bits/stdc++.h> // Incompleto
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 110


//MAXV = 10^9, MAX_PR = sqrt(MAXN); 
const int MAX_PR = 1000000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}


int v[MAXN]; int n; 

//chave: numero e 

int getmask(int k){
    int mask = 0;
    for(int i =1; i<=n; i++){
        int a = v[i];
        int cont = 0;

        while(a%k == 0){
            cont++;
            a/=k;
        }
        mask |= (1<<cont);
        
    }

    return mask;
}

map <pii, int> nimbers;

int grundy(int k, int mask){
    if(mask == 0) return 0;
    if(nimbers.find({k, mask}) != nimbers.end()){
        return nimbers[{k, mask}];
    }

    set<int> states;

    for(int i = 1; i <=30; i++){
        if(mask < (1<<i)) continue; //jogada invalida

        int newmask = (mask>>i)|(mask&((1<<i)-1));
        states.insert(grundy(k, newmask));
    }

    int gr = 0;
    while(states.find(gr) != states.end()) gr++;

    nimbers[{k, mask}] = gr;
    return gr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;
    for(int i =1; i<=n; i++) cin>>v[i];

    int sq = (int)sqrt(*max_element(v+1, v+1+n)) + 100;
    vi primes = eratosthenesSieve(sq);

    int xorval = 0;
    
    for(int i =1; i<=n; i++){
        if(v[i] <= 1) continue;
        bool primo = true;
        for(auto p: primes) {
            if(v[i] % p == 0){
                primo = false;
                break;
            }
        }

        if(primo) primes.push_back(v[i]);
    }
    
    //for(auto p: primes) cout<<p<<"\n";

    for(int p: primes){
        //cout<<"Grundy "<<p<<" = "<<grundy(p, getmask(p))<<"\n";
        int mask = getmask(p);
        if(mask > 1);
            xorval ^= grundy(p, mask);
    }
    //cout<<xorval<<"\n";
    if(xorval == 0) cout<<"Arpa\n";
    else cout<<"Mojtaba\n";

    return 0;
}