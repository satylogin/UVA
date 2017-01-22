#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int main()
{
	int t, tc, i, a, b, c;
	cin >> tc;

	for (t = 1; t <= tc; ++t) {
		cout << "Case " << t << ": ";
		cin >> a >> b >> c;
		if (a <= 20 && b<= 20 && c <= 20) {
			cout << "good" << endl;
		} else {
			cout << "bad" << endl;
		}
	}

	return 0;
}
