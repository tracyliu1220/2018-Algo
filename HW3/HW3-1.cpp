#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
string target, source;
int src[MAX];
int tar = 0, CUR = 0;
vector<vector<int>> G;
vector<vector<int>> GT;
int vis[MAX] = {0};
vector<int> order;

int DFS_G(int s) {
	vis[s] = 1;
	for (int i = 0; i < G[s].size(); i ++)
		if (!vis[G[s][i]]) DFS_G(G[s][i]);
	order.push_back(s);
}

int DFS_GT(int i) { // in GT
	int cur = 0;
	vis[i] = 1;
	stack<int> st;
	st.push(i);
	cur |= 1 << src[i];
	while (st.size()) {
		int x = st.top(); st.pop();
		for (int j = 0; j < GT[x].size(); j ++) {
			if (!vis[GT[x][j]]) {
				vis[GT[x][j]] = 1;
				cur |= 1 << src[GT[x][j]];
				st.push(GT[x][j]);
			}
		}
	}
	return cur;
}

void init() {
	cin >> n >> m;
	cin >> source;
	G.resize(n + 5);
	GT.resize(n + 5);

	for (int i = 0; i < n; i ++)
		src[i] = (int)source[i] - 'a';

	int u, v;
	for (int i = 0; i < m; i ++) {
		cin >> u >> v; u --; v --;
		G[u].push_back(v);
		GT[v].push_back(u);
	}

	cin >> target;
	for (int i = 0; i < target.size(); i ++)
		tar |= 1 << (int)(target[i] - 'a');
}


bool check(int cur) {
	int flag = 1;
	for (int i = 0; i < 26; i ++) 
    	if ((tar & (1 << i)) && !(cur & (1 << i)))
			flag = 0;
	if (flag) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	for (int i = 0; i < n; i ++)
		if (!vis[i]) DFS_G(i);

	memset(vis, 0, sizeof(vis));
	for (int i = n - 1; i >= 0; i --)
		if (!vis[order[i]]) {
			int cur = DFS_GT(order[i]);
			if (check(cur)) {
				cout << "Yes\n";
				return 0;
			}
		}
	

	cout << "No\n";
}
