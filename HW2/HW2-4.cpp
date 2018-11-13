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
	LL ans = 0;
	for (int i = 0; i < R.size(); i ++)
		for (int j = 0; j < B.size(); j ++)
			ans = max(ans, max(B[j].F - R[i].F, 0LL) * max(R[i].S - B[j].S, 0LL));

	cout << ans << '\n';
}
