#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ll arr[1000000];

int main()
{
	ll i, j, k, x, y, a, b, t, n, m, cur, ans;

	scanf("%lld", &t);
	for (ll it = 1; it <= t; ++it) {
		scanf("%lld", &n);
		for (i = 1; i < n; ++i) {
			scanf("%lld", &arr[i]);
		}

		a = -1;
		b = -2;
		cur = ans = 0;
		x = 1;
		y = 0;
		for (i = 1; i < n; ++i) {
			if (cur+arr[i] >= 0) {
				cur += arr[i];
				y++;
			} else {
				cur = 0;
				x = i+1;
				y = i;
			}

			if (cur > ans) {
				ans = cur;
				a = x;
				b = y;
			} else if (cur == ans) {
				if (b-a < y-x) {
					b = y;
					a = x;
				}
			}
		}
		if (cur > ans) {
			ans = cur;
			a = x;
			b = y;
		} else if (cur == ans) {
			if (b-a < y-x) {
				b = y;
				a = x;
			}
		}

		if (a != -1) {
			printf("The nicest part of route %lld is between stops %lld and %lld\n", it, a, b+1);
		} else {
			printf("Route %lld has no nice parts\n", it);
		}
	}

	return 0;
}
