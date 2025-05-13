#include <bits/stdc++.h> 
#define int long long int

using namespace std;

vector <string> letras = {
    ".-",   "-...",  "-.-.",  "-..",  ".",    "..-.",  "--.",   "....",
    "..",   ".---",  "-.-",   ".-..",  "--",   "-.",    "---",   ".--.",
    "--.-", ".-.",   "...",   "-",    "..-",  "...-",  ".--",   "-..-",
    "-.--", "--.."
};

int32_t main(){
    int t; cin>>t;
    while(t--){ 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string morse; cin>>morse;
        int n = morse.size();

        vector<int> dp(n+1, 0);
        dp[0]=1;

        int q; cin>>q;
        vector<string> words;
        for(int i = 0; i<q; i++){
            //a to morse
            string a, atom = ""; 
            cin>>a;

            for(int i = 0; (unsigned)i< a.length(); i++){
                int id = a[i] - 'A';
                atom += letras[id];
            }
            words.push_back(atom);
        }

        for(int i = 0; i<n; i++){
            if(dp[i] == 0) continue; //nao tem como chegar aqui
            for(auto c: words){
                int s = c.size();
                if(i+s > n) continue;
                if(morse.substr(i, s) != c) continue;
        
                dp[i+s] += dp[i];
            }
        }
        
        cout<<dp[n]<<endl;
    }
    return 0;
}