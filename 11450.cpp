#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

vector <int> v[30];
int dp[300][40], mark[300][40];
int n, x;

int rec(int m, int i)
{
	if (i == n) {
		//x = min(x, m);
		return m;
	}

	if (mark[m][i]) {
		return dp[m][i];
	} 

	mark[m][i] = 1;
	for (int j = 0; j < v[i].size(); ++j) {
		if (m-v[i][j] >= 0) {
			dp[m][i] = min(dp[m][i], rec(m-v[i][j], i+1));
		}
	}

	//cout << m << " " << i << " " << dp[m][i] << endl;

	return dp[m][i];
}

int main()
{
	int tc, i, j, a, b, c, m;
	cin >> tc;
	while (tc--) {
		cin >> m >> n;
		x = INT_MAX;
		for (a = 0; a <= 200; ++a) {
			for (b = 0; b <= 30; ++b) {
				mark[a][b] = 0;
				dp[a][b] = INT_MAX;
			}	
		}
		for (i = 0; i < n; ++i) {
			v[i].clear();
			cin >> a;
			while (a--) {
				cin >> j;
				v[i].pb(j);
			}
		}
		c = rec(m, 0);
		if (c == INT_MAX) {
			cout << "no solution" << endl;
		} else {
			cout << m-c << endl;
		}
	}

	return 0;
}
