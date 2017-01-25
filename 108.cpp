#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[101][101], tmp[101];

int main()
{
	int n, i, j, k, a, b, c;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}

	c = INT_MIN;
	for (i = 1; i <= n; ++i) {
		memset(tmp, 0, sizeof(tmp));
		for (j = i; j <= n; ++j) {
			a = 0; b = INT_MIN;
			for (k = 1; k <= n; ++k) {
				tmp[k] += arr[j][k];
				a = max(0, a+tmp[k]);
				b = max(a, b);
			}
			c = max(b, c);
		}
	}

	cout << c << endl;

	return 0;
}
