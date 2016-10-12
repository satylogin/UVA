#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int grid[26][26], n;
char str[10000][100];
int mark[26], exist[26];

void dfs(int s, int end, int idx)
{
	while (s < end && str[s][idx] == '\0') s++;
	if (s >= end) return;

	int i, j, start;
	for (start = s; start <= end; ++start) {
		for (i = start; i <= end; ++i) {
			if (str[start][idx] != str[i][idx]) {
				grid[str[i][idx]-'A'][str[start][idx]-'A'] = 1;
			}
		}
	}

	i = s; 
	while (i <= end) {
		j = i;
		while (j <= end && str[i][idx] == str[j][idx]) j++;
		dfs(i, j-1, idx+1);
		i = j;
	}
}

void dfs_(int x)
{
	mark[x] = 1;
	for (int i = 0; i < 26; ++i) {
		if (grid[x][i] && !mark[i]) {
			dfs_(i);
		}
	}
	cout << (char)(x+'A');
}	

int main()
{
	while (scanf("%s", str[n]) != EOF) {
		if (str[n][0] == '#') {
			dfs(0, n-1, 0);
			for (int i = 0; i < 26; ++i) {
				if (!mark[i] && exist[i]) dfs_(i);
			}
			cout << endl;
			break;
		} else {
			for (int i = 0; str[n][i]; ++i) exist[str[n][i]-'A'] = 1;
			n++;
		}
	}

	return 0;
}
