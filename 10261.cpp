#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int cost[10000], pr[1000], ct;

map <pair<int, pair<int, int> >, int > ans;
map <pair<int, pair<int, int> >, int > :: iterator it;

int ks(int x, int l1, int l2, int n) 
{
	if (x == n || (l1 == 0 && l2 == 0) || (cost[x] > l1 && cost[x] > l2)) {
		return 0;
	}	

	
	if (ans.find(mkp(x, mkp(l1, l2))) != ans.end()) return ans[mkp(x, mkp(l1, l2))];
	//if (it != ans.end()) return *it; 
	//return ans[x][l1][l2];
	//if (ans[x][l1][l2] != -1) return ans[x][l1][l2];

	int a, b, c;
	if (l1 >= cost[x]) a = 1 + ks(x+1, l1 - cost[x], l2, n);
	else a = -1;
	if (l2 >= cost[x]) b = 1 + ks(x+1, l1, l2 - cost[x], n);
	else b = -1;

	//cout << a << " " << b << endl;

	ct = max(ct, x+1);

	return (ans[mkp(x, mkp(l1, l2))] = max(a, b));
}

int main()
{
	int x, t, n, m, i, j, k, a, b, c, l1, l2;

	cin >> t;
	while (t--) {
		cin >> m;
		m *= 100;
		//memset(ans, -1, sizeof(ans));
		ans.clear();

		n = 0;
		while (cin >> x) {
			if (x == 0) break;
			cost[n++] = x;
		}

		//for (i = 0; i < n; ++i) cout << cost[i] << " "; cout << endl;

		ct = 0;
		ks(0, m, m, n);
		cout << ct << endl;

		l1 = l2 = m; x = ct-1;
		for (i = 1; i <= ct; ++i) {
			if (cost[i-1] <= l1 && ans[mkp(i, mkp(l1-cost[i-1], l2))] == x) {
 				cout << "port" << endl;
				l1 -= cost[i-1];
			} else {
				cout << "starboard" << endl;
				l2 -= cost[i-1];
			}
			x--;
		}

		if (t) cout << endl;
	}

	return 0;
}
