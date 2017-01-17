#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll ans[101][101];

int main()
{
	ll i, j, k, n;

	for (i = 0; i <= 100; ++i) {
		ans[i][1] = 1;
	}

	for (j = 1; j <= 100; ++j) {
		for (i = 0; i <= 100; ++i) {
			for (k = 0; k <= i; ++k) {
				ans[i][j] = (ans[i][j] + ans[i-k][j-1]) % MOD;
			}
		}
	}

	while (1) {
		cin >> i >> j;
		if (i == 0 && j == 0) break;
		cout << ans[i][j] << endl;
	}

	return 0;
}
