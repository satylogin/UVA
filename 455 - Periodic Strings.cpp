#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define eps 1e-9

vector<int> fail(string s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; s[i]; ++i) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (z[i] + i < n && s[z[i] + i] == s[z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int t, n, i, j, k, x, y;
	vector<int> z;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		n = s.size();
		z = fail(s);
		int ans = n;
		z[0] = n;
		for (i = n-1; i >= 0; --i) {
			if (z[i] == (n - i) && (n%z[i] == 0)) {
				bool ok = true;
				for (j = i; j >= 0; j -= z[i]) {
					if (z[j] < z[i]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ans = z[i];
					break;
				}
			}
		}
		cout << ans << endl;
		if (t) cout << endl;
	}

	return 0;
}
