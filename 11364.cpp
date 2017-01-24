#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[100], lef[100], righ[100];

int main()
{
	int t, n, i, j, m;

	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		sort(arr+1, arr+1+n);
		
		lef[1] = 0;
		for (i = 2; i <= n; ++i) {
			lef[i] = lef[i-1] + 2*(arr[i]-arr[i-1]);
		}
		righ[n] = 0;
		for (i = n-1; i > 0; --i) {
			righ[i] = righ[i+1] + 2*(arr[i+1]-arr[i]);
		}

		m = INT_MAX;
		for (i = 1; i <= n; ++i) {
			m = min(m, lef[i] + righ[i]);
		}
		cout << m << endl;
	}

	return 0;
}
