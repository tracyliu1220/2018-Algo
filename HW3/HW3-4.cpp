#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
typedef long long LL;

int n, m, K;

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

void init() {
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

bool MST(int k) {
    if (k < K) return false;

    init();
    _union(e[k].u, e[k].v);
    
    int cnt = 0;
    for (int i = 0; i < k; i ++) {
        if (find(e[i].u) == find(e[i].v)) continue;
        _union(e[i].u, e[i].v);
        cnt ++;
    }

    if (cnt >= K - 1) return true;
    else return false;
}

int BS() {
    int L = -1, R = n - 1, M;
    for (int i = 0; i < 20; i ++) {
        M = (L + R) / 2;
        cout << "L= " << L << " M= " << M << " R= " << R << '\n';
        if (MST(M)) R = M;
        else L = M;
    }

    return e[R].w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> K;

    e.resize(m);

    for (int i = 0; i < m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w; 
        e[i].u --; e[i].v --;
    }

    sort(e.begin(), e.end());

    cout << BS() << '\n';
}
