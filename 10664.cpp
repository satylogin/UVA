#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int ans[30][5000], fun[4000], cost[4000];
string str;

int main()
{
	int t, n, m, i, j, k, x;

	cin >> t;
	getline(cin, str);
	while (t--) {
		getline(cin, str);
		k = 0;
		n = 0;

		x = 0;
		for (i = 0; str[i]; ++i) {
			if (str[i] >= '0' && str[i] <= '9') x = x * 10 + (str[i] - '0');
			else {
				cost[n] = fun[n] = x;
				x = 0;
				k += cost[n];
				n++;
			}
		}
		cost[n] = fun[n] = x;
		x = 0;
		k += cost[n];
		n++;

//		for (i = 0; i < n; ++i) cout << cost[i] << " "; cout << endl;

/*
		for (i = 0; i < n; ++i) {
			cin >> cost[i];
			fun[i] = cost[i];
			k += cost[i];
		}
*/
		if (k&1) {
			cout << "NO" << endl;
			continue;
		}

		m = k / 2;
		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= m; ++j) {
				if (i == 0 || j == 0) ans[i][j] = 0;
				else if (cost[i-1] > j) ans[i][j] = ans[i-1][j];
				else ans[i][j] = max(ans[i-1][j], fun[i-1] + ans[i-1][j-cost[i-1]]);
			}
		}

		if (ans[n][m] == m) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
