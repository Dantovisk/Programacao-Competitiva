#include <bits/stdc++.h> // O editorial é horrível!!!!
using namespace std;     // Mesmo tentando de 20 formas diferentes, a solução deles
                         // sempre dá MLE, TLE, etc.

//Só passou com uma versão diferente que o gepeto passou
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        rt.resize(n);
        auto x = polar(1.0, acos(-1.0) / k);
        for (int i = k; i < 2 * k; i++) rt[i] = i & 1 ? rt[i / 2] * x : rt[i / 2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
            auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
            C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    // Para simular a rotação cíclica de s2 em relação a s1 via convolução:
    // Dobramos s1 e invertemos s2.
    int M = 1;
    while (M < 3 * n) M *= 2;

    vector<vector<C>> fa(26, vector<C>(M, 0));
    vector<vector<C>> fb(26, vector<C>(M, 0));

    for (int i = 0; i < n; i++) {
        fa[s1[i] - 'a'][i] = 1;
        fa[s1[i] - 'a'][i + n] = 1; // Dobra s1 para rotação
        fb[s2[i] - 'a'][n - 1 - i] = 1; // s2 invertida
    }

    for (int i = 0; i < 26; i++) {
        fft(fa[i]);
        fft(fb[i]);
    }

    vector<vector<C>> res(26, vector<C>(M, 0));
    for (int f = 0; f < M; f++) {
        for (int c = 0; c < 26; c++) {
            // Se fa[c][f] for zero, podemos pular para otimizar
            if (abs(fa[c][f]) < 1e-9) continue;
            for (int d = 0; d < 26; d++) {
                int k = (c - d + 26) % 26;
                res[k][f] += fa[c][f] * fb[d][f];
            }
        }
    }

    int max_matches = 0;
    for (int k = 0; k < 26; k++) {
        // IFFT manual: reverse(1..end) e divide por M
        reverse(res[k].begin() + 1, res[k].end());
        fft(res[k]);
        for (int i = n - 1; i < 2 * n - 1; i++) {
            max_matches = max(max_matches, (int)round(res[k][i].real() / M));
        }
    }

    cout << n - max_matches << endl;

    return 0;
}