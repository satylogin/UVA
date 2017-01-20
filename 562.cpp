#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int fun[101], cost[101], ans[101][50001];

int main()
{
	int t, n, m, i, j, k, a, b, c, x, y, z;

	cin >> t;
	while (t--) {
		cin >> n;
		m = 0;
		for (i = 0; i < n; ++i) {
			cin >> cost[i];
			fun[i] = cost[i];
			m += cost[i];
		}

		a = m;
		m /= 2;

		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= m; ++j) {
				if (i == 0 || j == 0) {
					ans[i][j] = 0;
				} else if (cost[i-1] > j) {
					ans[i][j] = ans[i-1][j];
				} else {
					ans[i][j] = max(fun[i-1] + ans[i-1][j-cost[i-1]], ans[i-1][j]);
				}
			}
		}

		cout << (a-ans[n][m]) - ans[n][m] << endl;
	}

	return 0;
}
