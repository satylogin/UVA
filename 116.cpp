#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int dp[8][601], freq[10], ans[601], ans1[601];

int main()
{
	int i, j, k, a, b, c, x, y, z;
	float f;

	int arr[] = {0, 5, 10, 20, 50, 100, 200};	

	for (i = 1; i <= 600; ++i) ans1[i] = MOD;

	for (i = 5; i <= 600; i += 5) {
		for (j = 1; j <= 6; ++j) {
			if (arr[j] <= i) {
				ans1[i] = min(ans1[i], 1 + ans1[i-arr[j]]);
			}
		}
	}

	while (scanf("%d %d %d %d %d %d", freq+1, freq+2, freq+3, freq+4, freq+5, freq+6)) {
		x = 0;
		
		for (i = 1; i <= 6; ++i) x += freq[i];
		
		if (x == 0) break;

		scanf("%f", &f);
		
		y = (int) (f*100);
		while (y%5) y++;

		for (i = 1; i <= 600; ++i) 
			ans[i] = MOD;

		memset(dp, 0, sizeof(dp));

		for (j = 5; j <= 600; j += 5) {
			for (i = 1; i <= 6; ++i) {
				if (arr[i] <= j) {
					if (1+dp[i][j-arr[i]] <= freq[i]) {
						if (ans[j-arr[i]] + 1 < ans[j]) {
							for (k = 1; k <= 6; ++k) {
								dp[k][j] = dp[k][j-arr[i]];
							}
							dp[i][j]++;
							ans[j] = ans[j-arr[i]] + 1;
						}
					}
				}
			}
/*
			cout << "*\n";
			for (j = 5; j <= 200; ++j) {
				if (ans[j] != MOD) cout << ans[j] << " ";
				else cout << -1 << " ";
			} cout << endl;
			cout << "*\n";

			for (j = 1; j <= 6; ++j) {
				for (k = 5; k <= 200; k += 5) {
					cout << dp[j][k] << " ";
				} cout << endl;
			} cout << endl;
*/
		}
/*
		for (i = 1; i <= 6; ++i) {
			for (j = 5; j <= 200; j += 5) {
				cout << dp[i][j] << " ";
			} cout << endl;
		}
*/
		x = MOD;
		for (i = y; i <= 600; i += 5) {
			x = min(x, ans[i] + ans1[i-y]);
			//cout << y << " " << ans[y] << " " << ans[i-y] << endl;
		}

		printf("%3d\n", x);
	}

	return 0;
}
