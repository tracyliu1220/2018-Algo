#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int M = N*(N-1)/2;
const int LEN = (1<<M);

bitset<LEN> B;

void readB(){
    string s;
    cin >> s;

    int i=LEN-1;
    for (char c:s){
        int x;
        if ( 0<=c && c<='9' ) x = c-'0';
        else x = c-'A'+10;
        for (int j=0; j<4; j++, i--){
            B[i] = (x>>3)&1;
            x<<=1;
        }
    }
}

bool TST(const vector< pair<int,int> > &edges){
    // input: edge set of an 8 vertex simple graph G
    // output: return true if G contain a binary spanning tree, otherwise false
    // time complexity: O(m) where m = number of edge

    int G = 0;
    for ( auto e : edges ){
        int u = e.first;
        int v = e.second;
        if (u>v) swap(u,v);
        int idx = v*(v-1)/2+u;;
        if (u==v) idx = -1;
        G |= (1<<idx);
    }
    return B[G];
}

// Complete the solve function below.
void solve(){
    int n, m; cin >> n >> m;
	vector< pair<int,int> > edges;
    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v; // edge (u,v)
		edges.push_back( {u, v} );
    }
	edges.push_back( {0, 5} );
	edges.push_back( {5, 6} );
	edges.push_back( {6, 7} );
	bool legal = true;
	for (int i = 0; i < 5; i ++) {
		edges[m].first = i;
		legal &= TST(edges);
	}
	if (legal) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    readB();

    int T; cin >> T;
    while (T--) solve();
}

