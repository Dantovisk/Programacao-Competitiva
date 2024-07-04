#include <iostream>
#include <vector>		//nao ta funcionando legal
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000010;

int main()
{
	int n;
	int v[MAXN], dp[MAXN], opt[MAXN], ind[MAXN];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	dp[0] = -INF;

	for (int i = 1; i <= n; i++)	
		dp[i] = INF;

	for (int i = 0; i < n; i++)
	{
		int p = lower_bound(dp, dp + n + 1, v[i]) - dp;

		ind[p] = i;
		dp[p] = v[i];
		opt[i] = ind[p - 1];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
		if (dp[i] < INF) ans = i;

	cout << "Tamanho da maior subsequência crescente: " << ans << endl;

	vector<int> LIS;

	int curIndex = ind[ans];

	for (int i = ans; i > 0; i--)
	{
		LIS.push_back( curIndex );
		curIndex = opt[curIndex];
	}

	reverse(LIS.begin(), LIS.end());

	cout << "Subsequencia otima: ";

	for (int i = 0; i < (int)LIS.size(); i++)
		cout << v[LIS[i]] << " ";
}