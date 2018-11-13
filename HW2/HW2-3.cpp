#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 505
typedef long long LL;

LL dp[505][505][2];
LL ans[505];

LL solve(int h, int n, int state) {
	if (n < 0 || h < 0) return 0;
	if (dp[h][n][state] != -1) {
		return dp[h][n][state];
	}

	dp[h][n][state] = 0;

	if (h < n) return dp[h][n][state] = 0;
	if (n == 1 && h >= 2) return dp[h][n][state] = 1;
	if (state == 0 && n == h) return dp[h][n][state] = 1;
	if (state == 1 && n == h - 1) return dp[h][n][state] = 1;

	if (state == 0) { //black
		dp[h][n][state] = (solve(h - 1, n - 1, 0) + solve(h - 1, n - 1, 1)) % MOD * (solve(h - 1, n - 1, 0) + solve(h - 1, n - 1, 1) % MOD) % MOD;
	} else {
		dp[h][n][state] = solve(h - 1, n, 0) * solve(h - 1, n, 0) % MOD;
	}
	return dp[h][n][state];
}

LL Ans(int n) {
	if (ans[n] != -1) return ans[n];
	ans[n] = 0;
	for (int i = 1; i <= n; i ++) {
		ans[n] = ((solve(n, i, 0) + solve(n, i, 1)) % MOD + ans[n]) % MOD;
	}
	return ans[n];
}

int main() {
	memset(dp, -1, sizeof(dp));
	memset(ans, -1, sizeof(ans));
	ans[0] = 0;

	int T, tar; cin >> T; while (T --) {
		LL sum = 0;
		cin >> tar;
		cout << (MOD + Ans(tar) - Ans(tar - 1)) % MOD << '\n';		
	}
}
