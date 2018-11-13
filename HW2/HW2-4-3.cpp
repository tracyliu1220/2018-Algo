#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;
typedef long long LL;
#define F first
#define S second

vector<pii> r, b;
vector<pii> R, B;

bool cmpr(pii p, pii q) {
	if (p.F < q.F) return true;
	else if (p.F == q.F && p.S > q.S) return true;
	else return false;
}

bool cmpb(pii p, pii q) {
	if (p.F > q.F) return true;
	else if (p.F == q.F && p.S < q.S) return true;
	else return false;
}

int BS(LL tar) {
	int _l = 0, _r = R.size(), _m;
	for (int i = 0; i < 20; i ++) {
		_m = (_l + _r) / 2;
		if (R[_m].S < tar) _l = _m;
		else _r = _m;
	}
	return _r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	r.resize(m); b.resize(n);

	for (int i = 0; i < m; i ++) cin >> r[i].F >> r[i].S;
	for (int i = 0; i < n; i ++) cin >> b[i].F >> b[i].S;

	sort(r.begin(), r.end(), cmpr);
	sort(b.begin(), b.end(), cmpb);
/*
	for (int i = 0; i < m; i ++) cout << r[i].F << ' ' << r[i].S << '\n';
	cout << '\n';
	for (int i = 0; i < n; i ++) cout << b[i].F << ' ' << b[i].S << '\n';
*/

	R.push_back(r[0]);
	B.push_back(b[0]);
	for (int i = 1; i < m; i ++) 
		if (r[i].S > (R.end() - 1)->S) R.push_back(r[i]);
	for (int i = 1; i < n; i ++)
		if (b[i].S < (B.end() - 1)->S) B.push_back(b[i]);
/*
	for (int i = 0; i < B.size(); i ++)
		cout << B[i].F << ' ' << B[i].S << '\n';
*/
	LL ans = 0, area;
	for (int i = 0; i < B.size(); i ++)
		for (int j = BS(B[i].S); j < R.size(); j ++) {
			area = max(B[i].F - R[j].F, 0LL) * max(R[j].S - B[i].S, 0LL);
			ans = max(ans, area);
			if (area == 0) break;
		}

	cout << ans << '\n';
}
