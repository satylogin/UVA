#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll ans[22][10001], arr[40];

int main()
{
	ll i, j, k, a, b, c, x, y, z;

	for (i = 1; i <= 21; ++i) 
		arr[i] = i*i*i;

	for (i = 1; i <= 21; ++i) {
		for (j = 0; j <= 10000; ++j) {
			if (j == 0) {
				ans[i][j] = 1;
			} else {
				ans[i][j] = ans[i-1][j];
				if (arr[i] <= j) {
					ans[i][j] += ans[i][j-arr[i]];
				}	
			}
		}
	}

	while (scanf("%lld", &x) != EOF) {
		printf("%lld\n", ans[21][x]);
	}

	return 0;
}
