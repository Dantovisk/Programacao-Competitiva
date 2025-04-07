#include <bits/stdc++.h>
 
using namespace std;
 
set <string> estados;
int n, w, h, l;
 
int main(){
    cin>>n>>w>>h>>l;
 
    vector<string> s(h);
    string a = "";
 
    for(int i =0; i<h; i++){
        cin>>s[i];
        a += s[i];
    }
 
    queue <pair<string,int>> q;
    estados.insert(a);
    q.push({a, 0});
 
    while(!q.empty()){
        auto [u, temp] = q.front();
        q.pop();

        vector<string> st;
        for(int i =0; i< h; i++){
            st.push_back(u.substr(i*w, w));
        }
        //for (auto x: st) cout<<x<<"\n";
        //cout<<temp<<"\n\n";

        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        //encontra as posições x e y dos robos
            
        if(temp == l) continue;

        for(int i =0; i< h; i++){
            for(int j =0; j< w; j++){
                if(st[i][j] - '0' >= 0 && st[i][j] - '0' < 6) {
                    //encontrou um robo
                    for(auto d: dir){
                        vector<string> st2 = st;
                        int ai = i + d[0],  aj = j + d[1];
                        while(ai >= 0 && ai < h && aj >=0 && aj < w){
                            if(st2[ai][aj] == 'W' || (st2[ai][aj] - '0' > 0 && st2[ai][aj] - '0' < 6)) break;
                            
                            ai += d[0];
                            aj += d[1];
                        }
                        ai -= d[0];  
                        aj -= d[1];
                        if(st2[ai][aj] == 'X'){
                            if(st2[i][j] != '1') continue;
                            cout<<temp+1<<endl;
                            while(!q.empty()) q.pop();
                            return 0;
                        }
                        swap(st2[ai][aj], st2[i][j]);

                        string st3 = "";
                        for(auto x : st2) st3 += x;

                        if (estados.find(st3) == estados.end()) {
                            estados.insert(st3);
                            q.push({st3, temp+1});
                        }
                    }
                }
            }
        }
    }
 
    cout<<"NO SOLUTION\n";
    return 0;
}