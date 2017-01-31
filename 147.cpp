#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll ans[20][30001];

int main()
{
	ll i, j, k, a, b, c;
	long double x;
	ll arr[] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

	for (i = 1; i <= 11; ++i) {
		for (j = 0; j <= 30000; ++j) {
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

	while (scanf("%LF", &x) != EOF) {
		a = (ll) (x*100);
		//cout << a << endl;
		if (a == 0) break;
		while (a%5) a++;
		printf("%6.2LF%17lld\n", x, ans[11][a]);
	}

	return 0;
}
