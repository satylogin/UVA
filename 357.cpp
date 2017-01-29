#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll ans[60][30001];

int main()
{
	ll i, j, k, a, b, c;
	ll arr[] = {0, 1, 5, 10, 25, 50};

	for (i = 1; i <= 5; ++i) {
		for (j = 0; j <= 30000; ++j) {
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

	while (scanf("%lld", &a) != EOF) {
		b = ans[5][a];
		if (b == 1) {
			printf("There is only 1 way to produce %lld cents change.\n", a);
		} else {
			printf("There are %lld ways to produce %lld cents change.\n", b, a);
		}
	}

	return 0;
}
