#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll ans[50][7490];

int main()
{
	ll i, j, k, n, t;

	ll arr[] = {0, 1, 5, 10, 25, 50};
	for (i = 1; i <= 5; ++i) {
		for (j = 0; j <= 7489; ++j) {
			if (i == 1 || j == 0) {
				ans[i][j] = 1;
			} else {
				ans[i][j] = ans[i-1][j];
				if (arr[i] <= j) {
					ans[i][j] += ans[i][j-arr[i]];
				}
			}
		}
	}

	while (cin >> n) {
		cout << ans[5][n] << endl;
	}

	return 0;
}
