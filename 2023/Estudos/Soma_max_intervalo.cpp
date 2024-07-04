#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1000010;

int main()
{
    int n;      //opt é optimal, ou intervalo ótimo
    int v[MAXN], dp[MAXN], opt[MAXN]; // opt[i] = índice mais a direita menor ou igual a i tal que s( opt(i) , i ) = dp(i)
    //v são os valores dados e dp a soma de prefixos

    cin >> n;

    for (int i = 0; i < n; i++)  //leitura do intervalo
        cin >> v[i];

    dp[0] = v[0];   // definição dos casos iniciais
    opt[0] = 0;

    for (int i = 1; i < n; i++)  //começa em 1 pq o 0 já foi definido
    {
        // Calculando opt[i]
        if (v[i] >= dp[i - 1] + v[i])  //se o termo atual for maior que a soma de prefixo anterior mais
            opt[i] = i;                //o termo atual, então o indice ótimo é o atual
        else                           //caso contrário, o indice ótimo
            opt[i] = opt[i - 1];       //continua sendo o anterior, até que deixe de ser maior

        dp[i] = max(v[i], dp[i - 1] + v[i]); //definição do maior intervalo
    }

    int answer = -INF;
    int indexMaxDp = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > answer) 
        {
            answer = dp[i]; // Pegando a maior dp
            indexMaxDp = i; // Pegando o índice da maior dp
        }
    }

    cout << "Soma: " << answer<< endl;  //já calculamos o indice de inicio do intervalo ótimo
    cout << "Intervalo: " << opt[indexMaxDp] << ", " << indexMaxDp;
}