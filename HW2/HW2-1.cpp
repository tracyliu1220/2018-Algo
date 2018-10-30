#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MAX 1e8+5

int n;
int G[MAXN][MAXN];
int dp[MAXN][MAXN];

int solve(int k) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (!i && !j) continue;
			if (i && abs(G[i][j] - G[i - 1][j]) <= k) 
				dp[i][j] |= dp[i - 1][j];
			if (j && abs(G[i][j] - G[i][j - 1]) <= k) 
				dp[i][j] |= dp[i][j - 1];
		}
	}
	return dp[n - 1][n - 1];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			cin >> G[i][j];

	int L = -1, R = MAX, M;
	while (R - L > 1) {
		M = (L + R) / 2;
		if (solve(M)) R = M;
		else L = M;
	}

	cout << R << '\n';
}
