#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int main()
{
	int t, n, l;
	char str[1000];

	cin >> t;
	while (t--) {
		cin >> n;
		n *= 567;
		n /= 9;
		n += 7492;
		n *= 235;
		n /= 47;
		n -= 498;
		sprintf(str, "%d", n);
		l = strlen(str);
		if (l >= 2) cout << (str[l-2] - '0') << endl;
		else cout << 0 << endl;
	}

	return 0;
}
