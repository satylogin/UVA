#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll dp[1001][1001], ans[1001], ans1[301][301];

int main()
{
	ll i, j, k, a, b, c, x, y, z;
	
	dp[0][0] = 1ll;
	for (i = 1; i <= 300; ++i) {
		for (j = i; j <= 1000; ++j) {
			for (k = 1; k <= j && k <= 1000; ++k) {
				dp[j][k] += dp[j-i][k-1];
			}
		}
	}

	string str;
	while (getline(cin, str)) {
		x = y = z = -1;
		i = 0;
		while (str[i]) {
			if (x == -1) {
				x = 0;
				while (str[i] && str[i] >= '0' && str[i] <= '9') {
					x = x * 10 + (str[i]-'0');
					i++;
				}
				if (str[i]) i++;
			} else if (y == -1) {
				y = 0;
				while (str[i] && str[i] >= '0' && str[i] <= '9') {
					y = y * 10 + (str[i]-'0');
					i++;
				}
				if (str[i]) i++;
			} else if (z == -1) {
				z = 0;
				while (str[i] && str[i] >= '0' && str[i] <= '9') {
					z = z * 10 + (str[i]-'0');
					i++;
				}
				if (str[i]) i++;
			}
		}
		if (y == -1) {
			a = 0;
			for (i = 0; i <= 1000; ++i) a += dp[x][i];
			cout << a << endl;
		} else if (z == -1) {
			a = 0;
			for (i = 0; i <= y; ++i)  a += dp[x][i];
			cout << a << endl;
		} else {
			a = 0;
			for (i = y; i <= z; ++i) a += dp[x][i];
			cout << a << endl;
		}
	}

	return 0;
}
