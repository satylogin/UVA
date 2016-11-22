#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

vector <int> v[100];
int exist[100], mark[100], deg[100], arr[100], n, fg;
char str[100000];

void dfs(int x, int i)
{
	int j, k, a, b, cnt = 0;
	//cout << x << " " << i << endl;
	if (i == n-1) {
		fg = 1;
		arr[i] = x;
		for (j = 0; j < n; ++j) {
			printf("%c", arr[j]+'A');
			if (j != n-1) printf(" ");
		}
		printf("\n");
		return;
	}

	mark[x] = 1;
	arr[i] = x;
	for (j = 0; j < v[x].size(); ++j) {
		deg[v[x][j]]--;
	}

	for (j = 0; j < 26; ++j) {
		if (!mark[j] && exist[j] && deg[j] == 0) {
			dfs(j, i+1);
			cnt++;
		}
	}

	mark[x] = 0;
	for (j = 0; j < v[x].size(); ++j) {
		deg[v[x][j]]++;
	}
}

int main()
{
	int t, m, i, j, k, a, b, x, y;
	cin >> t;
	gets(str);
	while (t--) {
		memset(exist, 0, sizeof(exist));
		memset(deg, 0, sizeof(deg));
		for (i = 0; i < 26; ++i) {
			v[i].clear();
		}
		fg = 0;

		gets(str);
		gets(str);
		n = 0;
		for (i = 0; str[i]; ++i) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				exist[str[i]-'A'] = 1;
				n++;
			}
		}
		gets(str);
		for (i = 0; str[i]; ++i) {
			if (str[i] >= 'A' && str[i] <= 'Z' && str[i+1] == '<') {
				v[str[i]-'A'].pb(str[i+2]-'A');
				deg[str[i+2]-'A']++;
			}
		}

		for (i = 0; i < 26; ++i) {
			if (exist[i] && deg[i] == 0) {
				dfs(i, 0);
			}
		}

		if (fg == 0) {
			cout << "NO" << endl;
		}

		if (t) cout << endl;
	}

	return 0;
}
