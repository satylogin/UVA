#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[200];

int main()
{
	int n, c, i, t = 1, x;
	while (cin >> n) {
		if (n == 0) break;
		cout << "Set #" << t++ << endl;
		c = x = 0;
		for (i = 0; i < n; ++i) {
			cin >> arr[i];
			x += arr[i];
		}
		x /= n;
		for (i = 0; i < n; ++i) {
			if (arr[i] > x) c += (arr[i] - x);
		}
		cout << "The minimum number of moves is " << c << ".\n\n";
	}		

	return 0;
}
