#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int ans[10001][100], fun[10000], cost[10000], wt[10000];

int main()
{
	int t, n, m, i, j, k, a, b, c, x, y, z;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> fun[i] >> cost[i];
		}

		cin >> a;
		m = 0;
		for (i = 0; i < a; ++i) {
			cin >> wt[i];
			m = max(m, wt[i]);
		}

		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= m; ++j) {
				if (i == 0 || j == 0) {
					ans[i][j] = 0;
				} else if (cost[i-1] > j) {
					ans[i][j] = ans[i-1][j];
				} else {
					ans[i][j] = max(ans[i-1][j], fun[i-1] + ans[i-1][j-cost[i-1]]);
				}
			}
		}

		ll sum = 0;
		for (i = 0; i < a; ++i) {
			sum += ans[n][wt[i]];
		}

		cout << sum << endl;
	}

	return 0;
}
