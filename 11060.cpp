#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

vector <int> v[101];
map <string, int> mp1;
map <int, string> mp2;
stack <int> st;
int mark[101], deg[101];
char str[101], str1[101];

int main()
{
	int n, m, i, j, k, a, b, c, x, y, z, cs = 1;
	string s;

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; ++i) {
			v[i].clear();
		}
		mp1.clear();
		mp2.clear();
		memset(mark, 0, sizeof(mark));
		memset(deg, 0, sizeof(deg));

		for (i = 1; i <= n; ++i) {
			scanf("%s", str);
			s = string(str);
			mp1[s] = i;
			mp2[i] = s;
		}

		scanf("%d", &m);
		while (m--) {
			scanf("%s %s", str, str1);
			x = mp1[string(str)];
			y = mp1[string(str1)];
			v[x].pb(y);
			deg[y]++;
		}

		printf("Case #%d: Dilbert should drink beverages in this order: ", cs++);

		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (!mark[j] && deg[j] == 0) {
					cout << mp2[j];
					if (i == n) cout << ".";
					else cout << " ";
					for (k = 0; k < v[j].size(); ++k) {
						deg[v[j][k]]--;
					}
					mark[j] = 1;
					break;
				}
			}
		}

		puts("");
		puts("");
	}

	return 0;
}
