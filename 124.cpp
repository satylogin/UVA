#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

map <char, int> mp;
map <int, char> mp1;
vector <int> v[100];

vector <string> ans;
string s;

int n, m, indeg[100], mark[100], stk[100];
char str[10000], cnt[10000];

void dfs(int x, int i, int A[])
{
	int j, k, a, b, tmp[100];
	mark[x] = 1;
	stk[i] = x;
	//cout << x << " " << i << endl;

	for (j = 0; j < v[x].size(); ++j) {
		A[v[x][j]]--;
	}

	if (i == n-1) {
		s = "";
		for (j = n-1; j >= 0; --j) {
			s += mp1[stk[j]];
		}
		ans.pb(s);
		mark[x] = 0;
		return;
	}

	for (j = n; j > 0; --j) {
		if (!mark[j] && A[j] == 0) {
			for (k = 1; k <= n; ++k) {
				tmp[k] = A[k];
			}
			dfs(j, i+1, tmp);
		}
	}

	mark[x] = 0;
	for (j = 0; j < v[x].size(); ++j) {
		A[v[x][j]]++;
	}
}

int main()
{
	int i, j, k, x, y, tmp[100];
	gets(str);
	while (1) {
		mp.clear();
		mp1.clear();
		ans.clear();
		memset(indeg, 0, sizeof(indeg));
		n = 0;
		j = 0;

		for (i = 0; str[i]; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				cnt[j++] = str[i];
			}
		}

		sort(cnt, cnt+j);

		for (i = 0; i < j; ++i) {
			mp[cnt[i]] = ++n;
			mp1[n] = cnt[i];
		}	
		
		for (i = 1; i <= n; ++i) {
			v[i].clear();
		}

		gets(str);
		x = y = -1;
		for (i = 0; str[i]; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				y = mp[str[i]];
				if (x == -1) {
					x = y;
				} else {
					v[y].pb(x);
					indeg[x]++;
					x = -1;
				}
			}
		}

		//for (i = 1; i <= n; ++i) {
		//	cout << i << ": ";
		//	for (j = 0; j < v[i].size(); ++j) {
		//		cout << v[i][j] << " ";
		//	} cout << endl;
		//}

		for (i = n; i > 0; --i) {
			if (indeg[i] == 0) {
				for (j = 1; j <= n; ++j) {
					tmp[j] = indeg[j];
				}
				dfs(i, 0, tmp);
			}
		}
	
		sort(ans.begin(), ans.end());

		for (i = 0; i < ans.size(); ++i) {
			cout << ans[i] << endl;
		}

		if (gets(str)) cout << endl;
		else break;
	}

	return 0;
}
