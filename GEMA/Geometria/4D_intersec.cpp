#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 100010
const int INF = 1e9 + 69;

// Gauss
//
// Resolve sistema linear
// Retornar um par com o numero de solucoes
// e alguma solucao, caso exista
//
// O(n^2 * m)

template<typename T>
pair<int, vector<T>> gauss(vector<vector<T>> a, vector<T> b) {
 const double eps = 1e-6;
 int n = a.size(), m = a[0].size();
 for (int i = 0; i < n; i++) a[i].push_back(b[i]);

 vector<int> where(m, -1);
 for (int col = 0, row = 0; col < m and row < n; col++) {
  int sel = row;
  for (int i=row; i<n; ++i)
   if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
  if (abs(a[sel][col]) < eps) continue;
  for (int i = col; i <= m; i++)
   swap(a[sel][i], a[row][i]);
  where[col] = row;

  for (int i = 0; i < n; i++) if (i != row) {
   T c = a[i][col] / a[row][col];
   for (int j = col; j <= m; j++)
    a[i][j] -= a[row][j] * c;
  }
  row++;
 }

 vector<T> ans(m, 0);
 for (int i = 0; i < m; i++) if (where[i] != -1)
  ans[i] = a[where[i]][m] / a[where[i]][i];
 for (int i = 0; i < n; i++) {
  T sum = 0;
  for (int j = 0; j < m; j++)
   sum += ans[j] * a[i][j];
  if (abs(sum - a[i][m]) > eps)
   return pair(0, vector<T>());
 }

 for (int i = 0; i < m; i++) if (where[i] == -1)
  return pair(INF, ans);
 return pair(1, ans);
}


int main() {
    cout<<fixed<<setprecision(15);

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin>>n;

    while(n--){
        double coefs[6][4];
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 4; j++){
                cin >> coefs[i][j];
            }
        }

        vector<vector<double>> v(4, vector<double>(4));
        vector<double> res(4);

        
        for(int i =0; i<4; i++){
            v[i][0] = coefs[1][i] ;
            v[i][1] = coefs[2][i] ;
            v[i][2] = - coefs[4][i] ;
            v[i][3] = - coefs[5][i];
            res[i] = coefs[3][i] - coefs[0][i];
        }

        auto r = gauss(v, res);

        if(r.first == 0 || r.first == INF) {
            cout<<"-1\n";
        }
        else{
            auto u = r.second;
            cout<<u[0]<<" "<<u[1]<<" "<<-u[2]<<" "<<-u[3]<<"\n";
        }
    }

}