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

LL Area(pii r, pii b) {
	return max(b.F - r.F, 0LL) * max(r.S - b.S, 0LL);
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
		if (r[i].S >= (R.end() - 1)->S) R.push_back(r[i]);
	for (int i = 1; i < n; i ++)
		if (b[i].S <= (B.end() - 1)->S) B.push_back(b[i]);
/*
	cout << "*\n";
	for (int i = 0; i < R.size(); i ++)
		cout << R[i].F << ' ' << R[i].S << '\n';
	cout << '\n';
	for (int i = 0; i < B.size(); i ++)
		cout << B[i].F << ' ' << B[i].S << '\n';
*/

	int current = 0;
	int S = 0; //red
	LL cur_x;
	LL cur_y;

	int _r = 0, _b = B.size() - 1;
	LL ANS = 0;

	while (_r < R.size() && _b >= 0) {

		cur_x = B[_b].F;
		cur_y = R[_r].S;

		_r ++; _b --;

		while (_r < R.size() && _b >= 0) {
			int move = 0;
			if (R[_r].F < cur_x) {
				cur_y = max(cur_y, R[_r].S);
				_r ++; move = 1;
			}
			if (B[_b].S < cur_y) {
				cur_x = max(cur_x, B[_b].F);
				_b --; move = 1;
			}
			if (!move) break;
		}
		
		LL ans = 0, pre = 0, area;
		int cur = _r - 1, tmp = 0, state = 0; //red

		while (1) {
			if (state == 0) {
				for (int i = 0; i < B.size(); i ++) {
					area = Area(R[cur], B[i]);
					if (area > ans) {
						ans = area;
						tmp = i;
					}
				}
			} else {
				for (int i = 0; i < R.size(); i ++) {
					area = Area(R[i], B[cur]);
					if (area > ans) {
						ans = area;
						tmp = i;
					}
				}
			}
			if (pre == ans) break;
			state = !state;
			pre = ans;
			ans = 0;
			cur = tmp;
		}
		ANS = max(ANS, ans);
	}		
		
		LL ans = 0, pre = 0, area;
		int cur = 0, tmp = 0, state = 0; //red
		
		while (1) {
			if (state == 0) {
				for (int i = 0; i < B.size(); i ++) {
					area = Area(R[cur], B[i]);
					if (area > ans) {
						ans = area;
						tmp = i;
					}
				}
			} else {
				for (int i = 0; i < R.size(); i ++) {
					area = Area(R[i], B[cur]);
					if (area > ans) {
						ans = area;
						tmp = i;
					}
				}
			}
			if (pre == ans) break;
			state = !state;
			pre = ans;
			ans = 0;
			cur = tmp;
		}

	
	cout << max(ANS, ans) << '\n';
}
