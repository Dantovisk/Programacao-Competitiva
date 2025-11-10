#include <bits/stdc++.h>
using namespace std;
#include <cstdint>
#include <cassert>

#define double long double
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const int IND = 100;
const double pi = acos(-1);
const double pi2 = acos(-1)*2.0;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<double> v;
int n;

double x, y;
pair<double, int> best = {1e6+7, -1};

int randRange(int hi) {
    uniform_int_distribution<int> dis(0, hi - 1);
    return dis(rng);
}

double randDouble(double lo, double hi) {
    uniform_real_distribution<> dis(lo, hi);
    return dis(rng);
}

double dist(double a, double b){
    return sqrt(a*a+b*b);
}

pair<double, double> get_pos(vector<double>& ang){
    double a = 0, b = 0;
    int i = 0;
    for(auto theta: ang){
        double r = v[i];
        a += r * cos(theta);
        b += r * sin(theta);
        i++;
    }
    return {a, b};
}

double fit(vector<double>& ang){
    auto [a, b] = get_pos(ang);
    return dist(a-x, b-y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin>>n;
    v.resize(n);

    double R_max = 0;
    double L_max = 0;
    int max_idx = 0;

    rep(i, 0, n) {
        cin>>v[i];
        R_max += v[i];
        if (v[i] > L_max) {
            L_max = v[i];
            max_idx = i;
        }
    }
    
    cin>>x>>y;

    double R_min = max(0.0L, L_max - (R_max - L_max));
    double D_target = dist(x, y);
    double st = atan2(y, x);

    vector<vector<double>> ang(IND);
    vector<double> curra(IND), currb(IND), currfit(IND);

    rep(i, 0, IND){
        ang[i].resize(n);
        rep(j, 0, n){
            ang[i][j] = st + randDouble(-0.5, 0.5);
        }
    }

    rep(j, 0, n) ang[0][j] = st;
    rep(j, 0, n) {
        ang[1][j] = (j == max_idx) ? st : (st + pi);
    }

    rep(i, 0, IND){
        auto [a, b] = get_pos(ang[i]);
        curra[i] = a;
        currb[i] = b;
        currfit[i] = dist(a-x, b-y);
        best = min(best, {currfit[i], i});
    }


    for(double coef = 1; coef > 0.0002; coef*=0.5){
        rep(iter, 0, 100){
            pair<double, int> milior = best;
            rep(i, 0, IND){
                if(i == best.second) continue;
                
                double temp_a = curra[i];
                double temp_b = currb[i];

                int mutat = 1;
                if(coef > 0.01) mutat += randRange(3);
                
                //calcula em O(1) agora
                rep(xd, 0, mutat){
                    int id = randRange(n);
                    double r = v[id];

                    double old_theta = ang[i][id];
                    temp_a -= r * cos(old_theta);
                    temp_b -= r * sin(old_theta);
                    
                    double val = randDouble(-coef, coef);
                    ang[i][id] += val;
                    
                    double new_theta = ang[i][id];
                    temp_a += r * cos(new_theta);
                    temp_b += r * sin(new_theta);
                }

                double newfit = dist(temp_a - x, temp_b - y);

                if(newfit < currfit[i]){
                    curra[i] = temp_a;
                    currb[i] = temp_b;
                    currfit[i] = newfit;
                } else {
                    auto [a, b] = get_pos(ang[i]);
                    double check_fit = dist(a-x, b-y);
                    curra[i] = a;
                    currb[i] = b;
                    currfit[i] = check_fit;
                }
                
                milior = min(milior, {currfit[i], i});
            }
            best = min(best, milior);
    
            rep(i, 0, 20){
                int sortudo = randRange(IND);
                if(sortudo == best.second) continue;
                ang[sortudo] = ang[best.second];
                curra[sortudo] = curra[best.second];
                currb[sortudo] = currb[best.second];
                currfit[sortudo] = currfit[best.second];
            }
        }
    }

    double a = 0, b = 0;
    int i = 0;
    cout<<fixed<<setprecision(7);
    for(auto theta: ang[best.second]){
        double r = v[i];

        a+= r * cos(theta);
        b+= r * sin(theta);
        cout<<a<<" "<<b<<"\n";
        i++;
    }
}