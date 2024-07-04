#include <iostream>
#include <vector>
using namespace std;

int main() {	
	int V, n;
	cin >> V >> n;   //v é a soma, n é o n° de elementos

	vector<int> M(n);     //leitura dos valores
	for (int i = 0; i < n; i++) { 
		cin >> M[i];
	}

	vector<bool> dp(V + 1, false);
	dp[0] = true;

	for (int i = 0; i < n; i++) {
		for (int k = V - M[i]; k >= 0; k--) {
			if (dp[k] == true) {
				dp[k + M[i]] = true;
			}
		}
	}

	if (dp[V] == true)
		cout << "S" << endl;
	else
		cout << "N" << endl;

	return 0;
}