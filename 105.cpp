#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[10001];

int main()
{
	int t, a, b, c, x, y, z, i, j, k;
	i = 1;
	k = 0;
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		while (i < a) {
			if (arr[i] < k) {
				printf("%d %d ", i-1, arr[i]);
				k = arr[i];
			} else if (arr[i] > k) {
				printf("%d %d ", i, arr[i]);
				k = arr[i];
			}
			i++;
		}
		if (arr[i] < k) {
			printf("%d %d ", i-1, arr[i]);
			k = arr[i];
		}
		for (j = a; j <= c; ++j) {
			arr[j] = max(arr[j], b);
		}
	}
	while (i <= 10000) {
		if (arr[i] == 0) {
			printf("%d %d", i-1, 0); break;
		}
		if (arr[i] < k) {
			printf("%d %d ", i-1, arr[i]);
			k = arr[i];
		} else if (arr[i] > k) {
			printf("%d %d ", i, arr[i]);
			k = arr[i];
		}
		i++;
	}
	puts("");

	return 0;
}
