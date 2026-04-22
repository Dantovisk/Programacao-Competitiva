#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> lines(n);
        int res = 1;

        for(int i = 0; i< points.size(); i++){
            for(int j = 0; j< i; j++){
                int deu = false;
                for(int k = j+1; k< lines.size(); k++){
                    //vê se já tem uma reta
                }

                if(!deu) {
                    lines[i].emplace_back(0);
                    lines.back().push_back(points[i][0]);
                    lines.back().push_back(points[i][0]);
                    lines.back().push_back(points[i][0]);
                    lines.back().push_back(points[i][0]);
                    lines.back().push_back(2);
                    
                }
            }
        }
        
        return res;
    }
};