#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int ans[31][1001], mark[31][1001], fun[1001], cost[1001], pt[1001];

int fnt(int n, int wt)
{
	int a = 0, b = 0;
	if (n < 0 || wt <= 0) return 0;
	if (ans[n][wt] != -1) return ans[n][wt];
	if (cost[n] <= wt) a = fnt(n-1, wt-cost[n]) + fun[n];
	b = fnt(n-1, wt);

	if (a > b) {
		mark[n][wt] = 1;
		return (ans[n][wt] = a);
	} else {
		mark[n][wt] = -1;
		return (ans[n][wt] = b);
	}
}

int main()
{
	int z, t, n, m, i, j, k, w, a, b, c, x, y;

	z = 0;
	while (cin >> m >> w) {
		if (z) cout << endl;
		z = 1;

		memset(ans, -1, sizeof(ans));
		memset(mark, -1, sizeof(mark));

		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> cost[i] >> fun[i];
			cost[i] = 3 * w * cost[i];
			pt[i] = 0;
		}

		cout << fnt(n-1, m) << endl;

		k = 0;
		c = m;

		for (i = n-1; i >= 0; --i) {
			if (mark[i][c] == 1) {
				pt[i] = 1;
				k++;
				c -= cost[i];
			}
		}

		cout << k << endl;
		for (i = 0; i < n; ++i) {
			if (pt[i]) cout << cost[i] / (3*w) << " " << fun[i] << endl;
		}
	}

	return 0;
}
