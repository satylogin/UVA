#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int dp[100000], arr[10001];

int main()
{
	int t, n, lim, m, i, j, k, a, b, c, x, y, z;

	cin >> t;
	while (t--) {
		cin >> c;
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr, arr+n);

		lim = 0;
		dp[0] = 0;
		for (i = 1; i <= 30000; ++i) {
			dp[i] = MOD;
		}

		for (i = 0; i < n; ++i) {
			for (j = 30000-arr[i]-1; j >= 0; --j) {
				if (dp[j] != MOD)
					dp[j+arr[i]] = min(dp[j+arr[i]], dp[j]+1);
			}
		}

		for (i = c; i <= 30000; ++i) {
			if (dp[i] != MOD) break;
		}

		cout << i << " " << dp[i] << endl;
	}

	return 0;
}
