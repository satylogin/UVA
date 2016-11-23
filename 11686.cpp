#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

vector <int> v[1000001];
int deg[1000001];
queue <int> q;
queue <int> ans;

int main()
{
	int n, m, i, j, k, x, y, a, b;

	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) {
			break;
		}
		for (i = 1; i <= n; ++i) {
			v[i].clear();
			deg[i] = 0;
		}

		while (m--) {
			scanf("%d %d", &a, &b);
			v[a].pb(b);
			deg[b]++;
		}

		for (i = 1; i <= n; ++i) {
			if (deg[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			x = q.front();
			q.pop();
			for (i = 0; i < v[x].size(); ++i) {
				deg[v[x][i]]--;
				if (deg[v[x][i]] == 0) {
					q.push(v[x][i]);
				}
			}
			ans.push(x);
		}

		if (ans.size() == n) {
			while (!ans.empty()) {
				printf("%d\n", ans.front());
				ans.pop();
			}
		} else {
			while (!ans.empty()) {
				ans.pop();
			}
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
