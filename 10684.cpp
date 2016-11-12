#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[1000000];

int main()
{
	int n, i, j, k, a, b, c, cur, ans;

	while (scan(n) && n) {
		for (i = 0; i < n; ++i) {
			scan(arr[i]);
		}
		cur = ans = 0;
		for (i = 0; i < n; ++i) {
			cur = max(0, cur+arr[i]);
			ans = max(ans, cur);
		}

		if (ans == 0) {
			printf("Losing streak.\n");
		} else {
			printf("The maximum winning streak is %d.\n", ans);
		}
	}

	return 0;
}
