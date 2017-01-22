#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int get(string s)
{
	int l = s.size(), x = 0;
	switch(l) {
		case 3: if (s[0] == 'o') x++;
			if (s[1] == 'n') x++;
			if (s[2] == 'e') x++;
			if (x > 1) return 1;
			else x = 0;
			if (s[0] == 't') x++;
			if (s[1] == 'w') x++;
			if (s[2] == 'o') x++;
			if (x > 1) return 2;
		case 5: return 3;
	}
}

int main()
{
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << get(s) << endl;
	}

	return 0;
}
