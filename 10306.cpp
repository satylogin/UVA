#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int dp[301][301], a[50], b[50];

int main()
{
	int t, n, m, i, j, k, x, y, z;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		m = m*m;
		for (i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}

		for (i = 0; i <= 300; ++i) {
			for (j = 0; j <= 300; ++j) {
				dp[i][j] = MOD;
			}
		}
		dp[0][0] = 0;	

		for (i = 0; i <= 300; ++i) {
			for (j = 0; j <= 300; ++j) {
				for (k = 0; k < n; ++k) {
					if (a[k] <= i && b[k] <= j) {
						dp[i][j] = min(dp[i][j], dp[i-a[k]][j-b[k]] + 1);
					}
				}
			}
		}

		x = MOD;
		for (i = 0; i <= 300; ++i) {
			for (j = 0; j <= 300; ++j) {
				if (i*i + j*j == m && dp[i][j] != MOD) {
					x = min(x, dp[i][j]);
				}
			}
		}

		if (x == MOD) {
			cout << "not possible" << endl;
		} else {
			cout << x << endl;
		}
	}

	return 0;
}
