#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll int
#define ld long double
#define pb push_back
#define mkp make_pair

ll dp[188][1211][15], a, n, m;
ll prime[200], arr[1121];

ll fnt(ll id, ll sum, ll taken)
{
	if (sum == 0) {
		if (taken == m) return 1;
		else return 0;
	} else if (taken == m) {
		if (sum == 0) return 1;
		else return 0;
	} else if (id == a) {
		if (sum == 0 && taken == m) return 1;
		else return 0;
	} else if (sum-prime[id] < 0 || sum < 0 || taken >= m || (taken == m && sum > 0) || id >= a) {
		return 0;
	} else if (dp[id][sum][taken] != -1) {
		return dp[id][sum][taken];
	} else {
		return (dp[id][sum][taken] = 0 + fnt(id+1, sum, taken) + fnt(id+1, sum-prime[id], taken+1));
	}
}

int main()
{
	ll i, j, k, b, c, x, y, z, t;

	a = 0;
	for (i = 2; i <= 1120; ++i) {
		if (arr[i] == 0) {
			prime[a++] = i;
			for (j = i*i; j <= 1120; j += i) {
				arr[j] = 1;
			}	
		}
	}

	memset(dp, -1, sizeof(dp));
	fnt(0, 1120, 0);

	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		memset(dp, -1, sizeof(dp));
		x = fnt(0, n, 0);
		cout << x << endl;
	}

	return 0;
}
