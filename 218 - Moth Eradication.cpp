#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

const ld eps = 1e-9;

class Point {
	public:
		ld x, y;
		bool operator < (Point b) {
			if (fabsl(y-b.y) >= eps) return y < b.y;
			return x < b.x;
		}
};

Point pivot, A[1000001], hull[1000001];
int len, N;

int ccw(Point a, Point b, Point c) {
	ld area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (fabs(area) < eps) return 0;
	if (area > 0) return -1;
	return  1;
}

ld dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); 
}

bool polar_order(Point a, Point b) {
	int order = ccw(pivot, a, b);
	if (order == 0) return dist(pivot, a) < dist(pivot, b);
	return (order == -1);
}

void convex_hull() {
	len = 0;
	if (N < 3) {
		return;
	}
	int ans = 0;
	for (int i = 1; i < N; ++i) {
		if (A[i] < A[ans]) ans = i;
	}
	swap(A[0], A[ans]);
	pivot = A[0];
	sort(A+1, A+N, polar_order);
	hull[len++] = A[0];
	hull[len++] = A[1];
	hull[len++] = A[2];
	for (int i = 3; i < N; ++i) {
		while (len > 2 && ccw(hull[len-2], hull[len-1], A[i]) != -1) len--;
		hull[len++] = A[i];
	}
}

ld perimeter() {
	ld ans = 0;
	for (int i = 0; i < len; ++i) {
		ld tmp = sqrtl(dist(hull[i], hull[(i+1)%len]));
		ans += tmp;
	}
	return ans;
}

int main()
{
	int i, j, k, x, y, tc;
	tc = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		for (i = 0; i < N; ++i) cin >> A[i].x >> A[i].y;
		convex_hull();
		cout << "Region #" << tc++ << ":" << endl;
		cout << setprecision(1) << fixed;
		cout << "(" << hull[0].x << "," << hull[0].y << ")";
		for (i = len-1; i >= 0; --i) {
			cout << "-(" << hull[i].x << "," << hull[i].y << ")";
		} 
		cout << endl << "Perimeter length = " << setprecision(2) << fixed << perimeter() << endl;
	}

	return 0;
}
