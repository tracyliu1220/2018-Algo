#include <bits/stdc++.h>
using namespace std;
#define MAX 5005
typedef long long LL;

struct Edge {
    int u, v;
    LL w;
};

int n, m;
vector<Edge> e;
LL d[MAX];
LL INF = 0x3f3f3f3f3f3f3f3f;

void init() {
    cin >> n >> m;
    memset(d, INF, sizeof(d));
    e.resize(m + n);

    //check
    for (int i = 0; i < m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u --; e[i].v --; e[i].w *= -1;
    }

	for (int i = 0; i < n; i ++) {
		e[m + i].u = n; e[m + i].v = i; e[m + i].w = 0;
		d[i] = INF;
	}
}

LL Bellman_Ford(int s) { // n
	d[s] = 0;
	
	for (int i = 0; i < n; i ++) 
		for (int j = 0; j < m + n; j ++) 
			d[e[j].v] = min(d[e[j].v], d[e[j].u] + e[j].w);
	for (int i = 0; i < m + n; i ++)
		if (d[e[i].v] > d[e[i].u] + e[i].w)
			return INF;
	
	LL ret = INF;
	for (int i = 0; i < n; i ++) 
		ret = min(ret, d[i]);
	
	return -ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

	LL ans = Bellman_Ford(n);

	if (ans == INF) cout << "INF\n";
	else cout << ans << '\n';
}
