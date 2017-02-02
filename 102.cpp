#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

struct node {
	int b, g, c;
};

int main()
{
	node val[3];
	int z = 0;
	string str[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

	while (scanf("%d%d%d%d%d%d%d%d%d",&val[0].b,&val[0].g,&val[0].c,&val[1].b,&val[1].g,&val[1].c,&val[2].b,&val[2].g,&val[2].c) != EOF) 
	{
		int x, i, j, k, y;
		string s;
		x = MOD;

		for (i = 0; i < 6; ++i) {
			y = 0;
			switch(str[i][0]) {
				case 'B': y += val[1].b + val[2].b; break;
				case 'C': y += val[1].c + val[2].c; break;
				case 'G': y += val[1].g + val[2].g; break;
			}
			switch(str[i][1]) {
				case 'B': y += val[0].b + val[2].b; break;
				case 'C': y += val[0].c + val[2].c; break;
				case 'G': y += val[0].g + val[2].g; break;
			}
			switch(str[i][2]) {
				case 'B': y += val[1].b + val[0].b; break;
				case 'C': y += val[1].c + val[0].c; break;
				case 'G': y += val[1].g + val[0].g; break;
			}
			//cout << str[i] << " " << y << endl;
			if (y < x) {
				x = y;
				s = str[i];
			}
		}

		cout << s << " " << x << endl;
	}

	return 0;
}
