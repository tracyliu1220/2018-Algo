#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, m;
string target, source;
int tar[26];
int src[MAX];
int cur[26];
vector<vector<int>> G;
int vis[MAX] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> source;
	memset(tar, 0, sizeof(tar));
	G.resize(n + 5);

	for (int i = 0; i < n; i ++)
		src[i] = (int)source[i] - 'a';

	/*
	for (int i = 0; i <= n; i ++)
		cout << targ[i] << ' ';
	cout << '\n';
	*/

	int u, v;
	for (int i = 0; i < m; i ++) {
		cin >> u >> v; u --; v --;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	cin >> target;
	for (int i = 0; i < target.size(); i ++)
		tar[(int)target[i] - 'a'] = 1;

	// DFS
	int flag = 1;
	for (int i = 0; i < n; i ++) {

		memset(cur, 0, sizeof(cur));

		if (vis[i]) continue;
		vis[i] = 1;
		stack<int> st;
		st.push(i);
		cur[src[i]] = 1;

		while (st.size()) {
			int x = st.top(); st.pop();
			for (int j = 0; j < G[x].size(); j ++) {
				if (!vis[G[x][j]]) {
					vis[G[x][j]] = 1;
					cur[src[G[x][j]]] = 1;
					st.push(G[x][j]);
				}
			}
		}

/*		
		for (int i = 0; i < 26; i ++)
			cout << tar[i] << ' ';
		cout << '\n';

		for (int i = 0; i < 26; i ++)
			cout << cur[i] << ' ';
		cout << '\n';
*/		

		flag = 1;
		for (int i = 0; i < 26; i ++) {
			if (tar[i] && !cur[i])
				flag = 0;
		}
		
		
		if (flag) {
			cout << "Yes\n";
			break;
		}
	}

	if (!flag) cout << "No\n";


}
