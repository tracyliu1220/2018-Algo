#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
typedef long long LL;

struct Edge {
    int u, v;
    LL w;
    bool operator< (Edge rhs) {
        if (w < rhs.w) return true;
        else return false;
    }
};

vector<Edge> e;
int p[MAX];

void init(int n, int m) {
    e.resize(m);
    for (int i = 0; i < n; i ++)
        p[i] = i;
}

int find(int x) {
    if (x != p[x]) return p[x] = find(p[x]);
    else return x;
}

void _union(int a, int b) {
    int _a = find(a);
    int _b = find(b);
    p[_b] = _a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, K;
    cin >> n >> m >> K;

    init(n, m);

    for (int i = 0; i < m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w; 
        e[i].u --; e[i].v --;
    }

    sort(e.begin(), e.end());

    int cnt = 0;
	LL ans;
    for (int i = 0; i < m; i ++) {
        if (find(e[i].u) == find(e[i].v)) continue;
        _union(e[i].u, e[i].v);
        cnt ++;
        if (cnt == K) {
            ans = e[i].w;
            break;
        }
    }

    cout << ans << '\n';
    
}
