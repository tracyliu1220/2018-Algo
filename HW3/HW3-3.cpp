#include <bits/stdc++.h>
using namespace std;
#define MAX 5005
typedef long long LL;

struct Edge {
    int u, v;
    LL w;
    bool operator< (Edge rhs) {
        if (w < rhs.w) return true;
        else return false;
    }
};

int n, m;
vector<Edge> e;
LL d[MAX];
LL INF = 0x3f3f3f3f3f3f3f3f;

void input() {
    cin >> n >> m;
    memset(d, INF, sizeof(d));
    e.resize(m);

    //check
    for (int i = 0; i < m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u --; e[i].v --; e[i].w *= -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++)
    }
}
