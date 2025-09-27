#include <bits/stdc++.h>

using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


//char ->
unordered_map<char,vector<pair<int, int>>> cards;

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, int> p;
	vector<p> res;
	rep(i,0,sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;

    for(int i =0; i<n; i++){
        char k; int j;
        cin>>k>>j;
        cards[k].push_back({j, i});
    }

    ll res = 1e11 + 69;

    string per = "ERSW";

    for(auto c: "SWERC"){
        if(cards.find(c) == cards.end()) continue;
        sort(cards[c].begin(), cards[c].end());
    }

    while(next_permutation(per.begin(), per.end())){
        ll cont = 0;
        string uwu = per + "C";
        // cout<<uwu<<" ";

        vector<int> v(n);

        int id = 0;
        for(auto c: uwu){
            if(cards.find(c) == cards.end()) continue;

            for(auto [x, y]: cards[c]){
                // cont += abs(id-y); 
                v[id] = y; //Aqui
                id++;
            }
            
        }
        vi k = lis(v);
        // res = min(res, cont);
        res = min(res, n - (ll)k.size());
        // cout<<cont<<"\n";
    }

    cout<<res<<"\n";
}