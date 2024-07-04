#include <bits/stdc++.h> //incompleto
using namespace std;

int main()
{
	int n, m;
    cin>>n>>m;
	int dp[20][20]; // dp[i][j] = MSC entre os i primeiros números de A e os j primeiros de B
	vector <string> dicio(110), palav(1010);
    for (int i=0; i<n; i++){
        cin>>dicio[i];
    }
    for (int i=0; i<m; i++){
        cin>>palav[i];
    }
    
    for (int indice=0; indice<m; indice++){
        for (int consulta=0; consulta<n; consulta++){
            
            int s1= dicio[consulta].length();
            int s2= palav[indice].length();
            
            for (int i = 0; i <= s1; i++)
            {
                for (int j = 0; j <= s2; j++)
                {
                        dp[i][j] = 0;
                }
            }

            for (int i = 1; i <= s1; i++)
            {
                for (int j = 1; j <= s2; j++)
                {
                    // Calculando dp[i][j] 
                    if (dicio[consulta][i - 1] != palav[indice][j - 1]) 
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    else 
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
            
            int xd = dp[s1][s2]- palav[indice].length(); 
            int xd2= dp[s1][s2]-dicio[consulta].length();
           
            if(abs(xd) + abs(xd2) <=2 ){
                cout<<dicio[consulta]<<" ";
            }
        }
        cout<<endl;
    }
}