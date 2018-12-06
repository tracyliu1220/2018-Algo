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
int visGT[MAX] = {0};
int seq[MAX];

int DFS(int i) { // in GT
    int cur = 0;
    visGT[i] = 1;
    stack<int> st;
    st.push(i);
    cur |= 1 << src[i];
    while (st.size()) {
        int x = st.top(); st.pop();
        for (int j = 0; j < GT[x].size(); j ++) {
            if (!visGT[GT[x][j]]) {
                visGT[GT[x][j]] = 1;
                cur |= 1 << src[GT[x][j]];
                st.push(GT[x][j]);
            }
        }
    }
    return cur;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    // DFS in G
    int flag = 0;
    int idx = 0;
    for (int i = 0; i < n; i ++) {
        if (vis[i]) continue;
        stack<int> st;
        st.push(i);
        vis[i] = 1;
        seq[idx++] = i;
        while (st.size()) {
            int x = st.top(); st.pop();
        
            for (int j = 0; j < G[x].size(); j ++) {
                if (!vis[G[x][j]]) {
                    vis[G[x][j]] = 1;
                    seq[idx++] = G[x][j];
                    st.push(G[x][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        int x = seq[i];

        if (!visGT[x]) {
            CUR = DFS(x); // DFS in GT
        
            // check
            flag = 1;
            for (int i = 0; i < 26; i ++) {
                if ((tar & (1 << i)) && !(CUR & (1 << i)))
                    flag = 0;
            }
            
            if (flag) {
                cout << "Yes\n";
                return 0;
            }
        }
       
    }
    cout << "No\n";
}
